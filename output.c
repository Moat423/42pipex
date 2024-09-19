/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:06:21 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/19 13:03:25 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"


int	outfile(int argc, char *argv[], char *envp[])
{
	int		outfile;
	char	**command;
	char	*commpath;
	int		comnb;
	int		i;

	outfile = open(argv[argc - 1], O_TRUNC, O_CLOEXEC, O_CREAT, 00666);
	i = 0;
	//if infile invalid (error) then proceed with the second command
	return (EXIT_SUCCESS);
}

//saved
int	readfromfiletopipe(char *argv[], char *envp[])
{
	char	**command;
	char	*commpath;
	char	**paths;
	/* int		pipefd[2]; */

	paths = get_paths(envp);
	command = ft_split(argv[2], ' ');
	commpath = get_commpath(paths, command[0]);
	if (!commpath || !commpath)
	{
		if (commpath)
			free(commpath);
		return (free_char_array(command, EXIT_FAILURE));
	}
	ft_foxecute(command, commpath);
	free(commpath);
	free_char_array(command, 1);
	return (EXIT_SUCCESS);
}


int	ft_foxecute(char **command, char *commpath)
{
	pid_t	cpid;
	int		status;
	int		pipefd[2];

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
	else
		waitpid(cpid, &status, 0);
	return (EXIT_SUCCESS);
}
