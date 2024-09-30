/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/30 15:01:34 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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
			return (commpath);
		free(commpath);
	}
	ft_fprintf(2, "%s: command not found\n", command);
	return (NULL);
}

char	**get_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
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
	int		err;

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
		return (free_char_array(command, 127));
	execve(commpath, command, envp);
	err = errno;
	ft_fprintf(2, "%s: %s\n", command[0], strerror(err));
	free(commpath);
	free_char_array(command, 1);
	return (err);
}
