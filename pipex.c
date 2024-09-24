/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/24 16:05:03 by lmeubrin         ###   ########.fr       */
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
	pipex(argc, argv, envp, i);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		return (rperror("open"));
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (rperror("dup2"));
	close(outfile);
	exec_to_stdout(argv[argc - 2], envp);
	while (wait(NULL) > 0)
		;
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
