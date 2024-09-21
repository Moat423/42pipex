/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/21 15:40:29 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);
int	last_command(int argc, char *argv[], char **paths, int *pipefd);
int	readfromfiletopipe(int argc, char *argv[], char *envp[], int files[]);
int	ft_foxecute(char **command, char *commpath, int pipefd[]);
int	handle_command(int infile, int argc, char *commands[]);
int	invoke_command(int *pipes, char *command);
int	pipex(int argc, char *argv[], char *envp[]);
int	basic_read_stdin_to_print(void);

//files[0] = read end (in) files[1] = write end (out)
int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		files[2];

	errno = 0;
	if (basic_argc_checking(argc))
		return (EXIT_FAILURE);
	infile = open(argv[1], O_RDONLY, 0444);
	/* if (infile != -1) */
	/* { */
	/* 	if (dup2(infile, STDIN_FILENO) == -1) */
	/* 		return (rperror("dup2")); */
	/* } */
	/* if (infile != -1) */
	/* 	close(infile); */
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		return (rperror("open"));
	/* if (dup2(outfile, STDOUT_FILENO) == -1) */
	/* 	return (rperror("dup2")); */
	/* close(outfile); */
	files[0] = infile;
	files[1] = outfile;
	readfromfiletopipe(argc, argv, envp, files);
	return (EXIT_SUCCESS);
}

int	readfromfiletopipe(int argc, char *argv[], char *envp[], int *files)
{
	char	**command;
	char	*commpath;
	char	**paths;
	int		pipefd[2];
	int		stdoutsave;

	(void)argc;
	if (dup2(files[0], STDIN_FILENO) == -1)
		return (rperror("dup2"));
	close(files[0]);
	paths = get_paths(envp);
	command = ft_split(argv[2], ' ');
	if (!command)
		return (rperror("malloc"));
	commpath = get_commpath(paths, command[0]);
	if (!commpath)
		return (free_char_array(command, EXIT_FAILURE));
	if (pipe(pipefd) == -1)
		return (rperror("pipe"));
	stdoutsave = dup(STDOUT_FILENO);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (rperror("dup2"));
	ft_foxecute(command, commpath, pipefd);
	free(commpath);
	free_char_array(command, 1);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (rperror("dup2"));
	if (dup2(files[1], STDOUT_FILENO) == -1)
		return (rperror("dup2"));
	last_command(argc, argv, paths, pipefd);
	free_char_array(paths, 1);
	if (dup2(stdoutsave, STDOUT_FILENO) == -1)
		return (rperror("dup2"));
	close(stdoutsave);
	return (EXIT_SUCCESS);
}

int	last_command(int argc, char *argv[], char **paths, int *pipefd)
{
	char	**command;
	char	*commpath;

	command = ft_split(argv[argc - 2], ' ');
	if (!command)
		return (rperror("malloc"));
	commpath = get_commpath(paths, command[0]);
	if (!commpath || !commpath)
	{
		if (commpath)
			free(commpath);
		return (free_char_array(command, EXIT_FAILURE));
	}
	ft_foxecute(command, commpath, pipefd);
	free(commpath);
	free_char_array(command, 1);
	return (EXIT_SUCCESS);
}

int	ft_foxecute(char **command, char *commpath, int pipefd[])
{
	pid_t	cpid;
	int		status;

	cpid = fork();
	if (cpid == 0)
	{
		close(pipefd[0]);
		execve(commpath, command, NULL);
		perror("execve");
		close(pipefd[1]);
		return (EXIT_FAILURE);
	}
	else if (cpid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	else
		waitpid(cpid, &status, 0);
	close(pipefd[1]);
	return (EXIT_SUCCESS);
}

int	basic_argc_checking(int argc)
{
	if (argc == 1)
		ft_printf("pipex: parse error");
	if (argc > 5)
		ft_printf("pipex: ecxess argument(s)");
	if (argc == 1 || argc > 5)
		return (1);
	return (0);
}
