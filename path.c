/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/19 10:10:22 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/pipex.h"
#include "libft/lib_ft/libft.h"
#include "libft/libft_full.h"

char	**get_paths(char *envp[]);
char	*get_commpath(char **paths, const char *command);
char	*check_commpath(char *path, char *backslcomm);
int	execute(int argc, char *argv[], char *envp[]);
int	do_exec(char *commpath, char *command[]);

/* int	main(int argc, char *argv[], char *envp[]) */
/* { */
/* 	return (execute(argc, argv, envp)); */
/* } */

int	execute(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**command;
	char	*commpath;
	pid_t	cpid;
	int		status;
	/* int		pipefd[2]; */

	i = 0;
	if (argc == 1)
		return (0);
	command = ft_split(argv[2], ' ');
	commpath = get_commpath(envp, command[0]);
	/* if (pipe(pipefd) == -1) */
	/* 	perror("pipe"); */
	cpid = fork();
	if (cpid == 0)
	{
		ft_fprintf(1, "child about to execute\n");
		ft_printf("commpath: %s\n", commpath);
		ft_printf_char_array(command, 2);
		execve(commpath, command, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (cpid == -1)
		perror("fork");
	else
	{
		waitpid(cpid, &status, 0);
	}
	if (commpath)
		free(commpath);
	while (command[i])
		free(command[i++]);
	return (0);
}

int	do_exec(char *commpath, char *command[])
{
	int		pipefd[2];
	pid_t	cpid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
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
	return (EXIT_SUCCESS);
}

char	*get_commpath(char **paths, const char *command)
{
	int		i;
	char	*commpath;
	char	*saved_command;

	saved_command = ft_strjoin("/", command);
	i = 0;
	while (paths[i++])
	{
		commpath = check_commpath(paths[i], saved_command);
		if (commpath)
			break ;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(saved_command);
	return (commpath);
}

char	*check_commpath(char *path, char *backslcomm)
{
	char	*commpath;

	commpath = ft_strjoin(path, backslcomm);
	if (!commpath)
		return (NULL);
	else if (access(commpath, X_OK) == 0)
	{
		return (commpath);
	}
	free(commpath);
	return (NULL);
}

char	**get_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!strncmp("PATH=", envp[i], 5))
		{
			return (ft_split(envp[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
}
