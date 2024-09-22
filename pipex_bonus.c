/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:22:19 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/22 20:26:46 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	input_checker(int argc, char *arg);

int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		i;
	int		fileindicator;

	fileindicator = input_checker(argc, argv[1]);
	if (fileindicator == 0)
		return (EXIT_FAILURE);
	if (fileindicator == 1)
		infile = here_doc(argc, argv);
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

int	here_doc(argc, argv)

int input_checker(int argc, char *arg)
{
	if (argc <= 4)
	{
		ft_printf("pipex: parse error");
		return (0);
	}
	else if (ft_strncmp(arg, "here_doc", 8 == 0))
	{
		if (argc < 6)
		{
			ft_printf("pipex: parse error");
			return (0);
		}
		else
			return (2);
	}
	return (1);
}

