/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/18 17:13:44 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <stdlib.h>
#include <unistd.h>

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);
int	handle_command(int infile, int argc, char *commands[]);
int	invoke_command(int *pipes, char *command);
int	pipex(int argc, char *argv[], char *envp[]);
int	readfromfiletopipe(char *argv[], char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	char	line[10];

	(void)envp;
	errno = 0;
	if (basic_argc_checking(argc))
		return (EXIT_FAILURE);
	infile = get_fd(argv[1]);
	if (infile == -1)
		return (EXIT_FAILURE);
	dup2(infile, STDIN_FILENO);
	read(STDIN_FILENO, line, 10);
	ft_printf("read 10 bytes:%s,\n", line);
	/* return (pipex(argc, argv, envp)); */
	readfromfiletopipe(argv, envp);
	close(infile);
	return (EXIT_SUCCESS);
}

int	pipex(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	char	**command;
	char	*commpath;
	int		comnb;
	int		i;

	infile = get_fd(argv[1]);
	outfile = open(argv[argc - 1], O_TRUNC, O_CLOEXEC, O_CREAT, 00666);
	i = 0;
	//if infile invalid (error) then proceed with the second command
	comnb = 2;
	command = ft_split(argv[comnb], ' ');
	commpath = get_commpath(envp, command[0]);
	if (commpath)
		free(commpath);
	while (command[i])
		free(command[i++]);
	close(outfile);
	if (infile)
		close(infile);
	return (EXIT_SUCCESS);
}

//this one is working, all the other one have mistakes like missing ++!!!!!!!!
int	readfromfiletopipe(char *argv[], char *envp[])
{
	int		infile;
	char	**command;
	char	*commpath;
	int		i;
	pid_t	cpid;
	int		status;

	infile = get_fd(argv[1]);
	if (infile == -1)
		return (EXIT_FAILURE);
	i = 0;
	command = ft_split(argv[2], ' ');
	commpath = get_commpath(envp, command[0]);
	if (!commpath || !commpath)
	{
		close(infile);
		//clean command or commpath
		return (EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		return (EXIT_FAILURE);
	}
	close(infile);
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
	free(commpath);
	free_char_array(command, 1);
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
