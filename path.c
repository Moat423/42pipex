/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/24 16:04:21 by lmeubrin         ###   ########.fr       */
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

char	*get_commpath(char **paths, const char *command)
{
	int		i;
	char	*commpath;

	i = 0;
	while (paths[i])
	{
		commpath = ft_strjoin3(paths[i++], "/", command);
		if (!commpath)
			return (NULL);
		else if (access(commpath, X_OK) == 0)
			return (commpath);
		free(commpath);
	}
	ft_fprintf(2, "%s: command not found\n", command);
	return (NULL);
}

char	**get_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (!strncmp("PATH=", envp[i], 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

int	make_exec(char *arg, char *envp[])
{
	char	**paths;
	char	*commpath;
	char	**command;
	int		err;

	paths = get_paths(envp);
	command = ft_split(arg, ' ');
	if (!command || !paths)
	{
		free_char_array(command, 1);
		free_char_array(paths, 1);
		return (rperror("malloc"));
	}
	commpath = get_commpath(paths, command[0]);
	free_char_array(paths, 1);
	if (!commpath)
		return (free_char_array(command, 127));
	execve(commpath, command, envp);
	err = errno;
	ft_fprintf(2, "%s: %s\n", command[0], strerror(err));
	free(commpath);
	free_char_array(command, 1);
	errno = err;
	return (err);
}

int	pipex(int argc, char **argv, char **envp, int curr)
{
	pid_t	cpid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (rperror("pipe"));
	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			return (rperror("dup2"));
		close(pipefd[1]);
		make_exec(argv[curr], envp);
		exit (errno);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (rperror("dup2"));
	close(pipefd[0]);
	while (curr < argc - 2)
		pipex(argc, argv, envp, ++curr);
	waitpid(cpid, NULL, 0);
	return (EXIT_SUCCESS);
}

int	exec_to_stdout(char *arg, char **envp)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		make_exec(arg, envp);
		perror("execve");
		exit (EXIT_FAILURE);
	}
	else
		waitpid(cpid, NULL, 0);
	return (EXIT_SUCCESS);
}
