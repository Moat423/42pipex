/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/21 19:08:27 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		i;

	i = 2;
	if (basic_argc_checking(argc))
		return (EXIT_FAILURE);
	infile = open(argv[1], O_RDONLY, 0444);
	if (infile == -1)
		return (rperror("open"));
	if (dup2(infile, STDIN_FILENO) == -1)
		return (rperror("dup2"));
	close(infile);
	while (i < argc - 2)
		pipex(argv[i++], envp);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		return (rperror("open"));
	if (exec_to_outf(argv[argc - 2], envp, outfile) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	close(outfile);
	while (wait(NULL) > 0)
		;
	return (EXIT_SUCCESS);
}

int	pipex(char *arg, char **envp)
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
		make_exec(arg, envp);
		exit (rperror("execve"));
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (rperror("dup2"));
	close(pipefd[0]);
	waitpid(cpid, NULL, 0);
	return (EXIT_SUCCESS);
}

int	exec_to_outf(char *arg, char **envp, int outfile)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
		return (rperror("fork"));
	else if (cpid == 0)
	{
		if (dup2(outfile, STDOUT_FILENO) == -1)
			return (rperror("dup2"));
		close(outfile);
		make_exec(arg, envp);
		perror("execve");
		exit (EXIT_FAILURE);
	}
	else
		waitpid(cpid, NULL, 0);
	return (EXIT_SUCCESS);
}

int	basic_argc_checking(int argc)
{
	if (argc <= 4)
		ft_printf("pipex: parse error");
	if (argc > 5)
		ft_printf("pipex: ecxess argument(s)");
	if (argc <= 4 || argc > 5)
		return (1);
	return (0);
}
