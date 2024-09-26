/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/26 14:06:46 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "include/pipex.h"
#include "libft/lib_ft/libft.h"
#include "libft/libft_full.h"

//TODO: zero the pipe if the execution of one command fails
//TODO: also look at all outputs
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
	return (err);
}

int	exec_command(char *command, char *envp[], int in_fd, int out_fd)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			if (dup2(in_fd, STDIN_FILENO) == -1)
				return (rperror("dup2"));
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			if (dup2(out_fd, STDOUT_FILENO) == -1)
				return (rperror("dup2"));
			close(out_fd);
		}
		make_exec(command, envp);
		exit (errno);
	}
	return (cpid);
}

int	pipex(int argc, char **argv, char **envp, int curr)
{
	int		pipefd[2];
	int		prev_pipe;
	pid_t	last_pid;
	int		status;
	pid_t	cpid;

	prev_pipe = STDIN_FILENO;
	last_pid = -1;
	while (curr < argc - 2)
	{
		if (pipe(pipefd) == -1)
			return (rperror("pipe"));
		cpid = exec_command(argv[curr], envp, prev_pipe, pipefd[1]);
		if (cpid == -1)
			return (rperror("fork"));
		close(pipefd[1]);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		prev_pipe = pipefd[0];
		if (curr == argc - 3)
			last_pid = cpid;
		curr++;
	}
	last_pid = exec_command(argv[argc - 2], envp, prev_pipe, STDOUT_FILENO);
	if (last_pid == -1)
		return (rperror("fork"));
	if (prev_pipe != STDIN_FILENO)
		close(prev_pipe);
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (-1);
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
