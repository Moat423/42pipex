/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:22:19 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/21 19:35:36 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		i;

	if (is_heredoc(argc) == 1)
		return (EXIT_FAILURE);
	infile = open(argv[1], O_RDONLY, 0444);
	i = 2;
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

int	is_heredoc(int argc, char *argv[])

