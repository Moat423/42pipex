/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/19 10:46:12 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <stdlib.h>
#include <unistd.h>

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);
int	handle_command(int infile, int argc, char *commands[]);
int	ft_foxecute(char **command, char *commpath);
int	invoke_command(int *pipes, char *command);
int	pipex(int argc, char *argv[], char *envp[]);
int	readfromfiletopipe(char *argv[], char *envp[]);
int	basic_read_stdin_to_print(void);

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;

	(void)envp;
	errno = 0;
	if (basic_argc_checking(argc))
		return (EXIT_FAILURE);
	infile = get_fd(argv[1]);
	if (infile == -1)
		return (EXIT_FAILURE);
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		return (EXIT_FAILURE);
	}
	close(infile);
	/* basic_read_stdin_to_print(); */
	readfromfiletopipe(argv, envp);
	return (EXIT_SUCCESS);
}

int	basic_read_stdin_to_print(void)
{
	char	line[11];
	int		readbytes;

	ft_bzero(line, 11);
	readbytes = read(STDIN_FILENO, line, 10);
	ft_printf("read 10 bytes:%s,\n", line);
	return (readbytes);
}

//this one is working, all the other one have mistakes like missing ++!!!!!!!!
int	readfromfiletopipe(char *argv[], char *envp[])
{
	char	**command;
	char	*commpath;
	char	**paths;
	/* int		pipefd[2]; */

	paths = get_paths(envp);
	command = ft_split(argv[2], ' ');
	commpath = get_commpath(paths, command[0]);
	if (!commpath || !commpath)
	{
		if (commpath)
			free(commpath);
		return (free_char_array(command, EXIT_FAILURE));
	}
	ft_foxecute(command, commpath);
	free(commpath);
	free_char_array(command, 1);
	return (EXIT_SUCCESS);
}

int	ft_foxecute(char **command, char *commpath)
{
	pid_t	cpid;
	int		status;

	cpid = fork();
	if (cpid == 0)
	{
		execve(commpath, command, NULL);
		perror("execve");
		return (EXIT_FAILURE);
	}
	else if (cpid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	else
		waitpid(cpid, &status, 0);
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

int	get_fd(char *filename)
{
	int	fd;

	if (!filename)
		return (-1);
	if (access(filename, F_OK) == -1)
	{
		ft_fprintf(2, "pipex: no such file or directory: %s\n", filename);
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		ft_fprintf(2, "pipex: permission denied: nopermission\n");
		return (-1);
	}
	fd = open(filename, 0);
	if (fd == -1)
		perror("open");
	//mkdir and others need write permission!
	return (fd);
}
