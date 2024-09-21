/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/21 19:08:54 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/pipex.h"
#include "libft/lib_ft/libft.h"
#include "libft/libft_full.h"

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
			break ;
		free(commpath);
		commpath = NULL;
	}
	if (!commpath)
		ft_fprintf(2, "pipex: command not found: %s", command);
	i = 0;
	return (commpath);
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
		return (free_char_array(command, 1));
	execve(commpath, command, envp);
	free(commpath);
	free_char_array(command, 1);
	return (1);
}
