/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:22:19 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 17:33:58 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		fileindicator;

	fileindicator = input_checker(argc, argv[1]);
	i = 2;
	if (fileindicator == 2)
		pipheredoc(argv[i++]);
	else
		open_doc(argv[1], 0);
	while (i < argc - 2)
		pipex(argv[i++], envp);
	open_doc(argv[argc - 1], fileindicator);
	exec_to_stdout(argv[argc - 2], envp);
	return (EXIT_SUCCESS);
}

//opens file, dup2s over correct std fd, filekind 0:inf, 1:outf, 2:outf(append)
int	open_doc(char *file, int filekind)
{
	int	fd;

	if (filekind == 0)
	{
		fd = open(file, O_RDONLY, 0444);
		if (fd == -1)
			exit (rperror("open"));
		if (dup2(fd, STDIN_FILENO) == -1)
			exit (rperror("dup2"));
		close(fd);
		return (0);
	}
	if (filekind == 1)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == -1)
		exit (rperror("open"));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (rperror("dup2"));
	close(fd);
	return (0);
}

int	pipheredoc(char *arg)
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
		here_doc(arg);
		exit (0);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (rperror("dup2"));
	close(pipefd[0]);
	waitpid(cpid, NULL, 0);
	return (EXIT_SUCCESS);
}

int	input_checker(int argc, char *arg)
{
	if (argc <= 4)
	{
		ft_printf("pipex: parse error");
		exit (0);
	}
	else if (ft_strncmp("here_doc", arg, 8) == 0)
	{
		if (argc < 6)
		{
			ft_printf("pipex: parse error");
			exit (0);
		}
		else
			return (2);
	}
	return (1);
}
