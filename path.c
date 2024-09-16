/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/16 19:57:07 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "include/pipex.h"
#include "libft/lib_ft/libft.h"
#include "libft/libft_full.h"

char	**get_paths(char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int		i;
	char	**command;
	char	*commpath;

	i = 0;
	if (argc == 1)
		return (0);
	paths = get_paths(envp);
	while (paths[i])
		ft_printf("%s\n", paths[i++]);
	i = 0;
	command = ft_split(argv[2], ' ');
	while (command[i])
		ft_fprintf(1, "%s\n", command[i++]);
	while (paths[i])
	{
		commpath = ft_strjoin(paths[i], command[0]);
		if (!commpath)
			break ;
		if (access(commpath, X_OK))
		{
			ft_fprintf(1, "EXECUABLE FOUND\n");
			ft_fprintf(1, "%s\n", commpath);
			command[0] = STDIN_FILENO;
			ft_fprintf(1, "%s\n", command);
			if (fork() == 0)
				execve(commpath, command, envp);
			break ;
		}
		free(commpath);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	i = 0;
	while (command[i])
		free(command[i++]);
	(void) argv;
	return (0);
}

char	**get_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!strncmp("PATH=", envp[i], 5))
		{
			printf("%s\n", envp[i] + 5);
			return (ft_split(envp[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
}
