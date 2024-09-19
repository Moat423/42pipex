/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/19 15:55:06 by lmeubrin         ###   ########.fr       */
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

char	**get_paths(char *envp[]);
char	*get_commpath(char **paths, const char *command);

char	*get_commpath(char **paths, const char *command)
{
	int		i;
	char	*commpath;

	i = 0;
	while (paths[i++])
	{
		commpath = check_commpath(paths[i], command);
		if (commpath)
			break ;
	}
	if (!commpath)
		ft_fprintf(2, "pipex: command not found: %s", command);
	i = 0;
	return (commpath);
}

char	*check_commpath(char *path, const char *command)
{
	char	*commpath;

	commpath = ft_strjoin3(path, "/", command);
	if (!commpath)
		return (NULL);
	else if (access(commpath, X_OK) == 0)
		return (commpath);
	free(commpath);
	return (NULL);
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
