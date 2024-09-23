/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:22:19 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 12:00:53 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		i;
	int		fileindicator;

	fileindicator = input_checker(argc, argv[1]);
	i = 2;
	if (fileindicator == 1)
		pipheredoc(argv[i++]);
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
	exec_to_outf(argv[argc - 2], envp, outfile);
	while (wait(NULL) > 0)
		;
	return (EXIT_SUCCESS);
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
		exit (rperror("execve"));
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
	else if (ft_strncmp(arg, "here_doc", 8 == 0))
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
