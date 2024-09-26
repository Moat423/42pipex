/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:42:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/26 15:50:11 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	exec_command(char *command, char *envp[], int in_fd, int out_fd)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		close(in_fd);
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
	pid_t	last_pid;
	pid_t	cpid;

	while (curr < argc - 2)
	{
		if (pipe(pipefd) == -1)
			return (rperror("pipe"));
		cpid = exec_command(argv[curr], envp, pipefd[0], pipefd[1]);
		if (cpid == -1)
			return (rperror("fork"));
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			return (rperror("dup2"));
		close(pipefd[0]);
		if (curr == argc - 3)
			last_pid = cpid;
		curr++;
	}
	close(pipefd[0]);
	return (1);
}

int	exec_to_stdout(char *arg, char **envp)
{
	pid_t	cpid;
	int		status;

	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		make_exec(arg, envp);
		perror("execve");
		exit (EXIT_FAILURE);
	}
	waitpid(cpid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}
