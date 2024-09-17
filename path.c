/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/17 20:42:16 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "include/pipex.h"
#include "libft/lib_ft/libft.h"
#include "libft/libft_full.h"

char	**get_paths(char *envp[]);
char	*get_commpath(char *envp[], const char *command);
char	*check_commpath(char *path, char *slashcomm);

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**command;
	char	*commpath;
	pid_t	cpid;
	int		pipefd[2];

	i = 0;
	if (argc == 1)
		return (0);
	command = ft_split(argv[2], ' ');
	commpath = get_commpath(envp, command[0]);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
	}
	cpid = fork();
	if (cpid == 0)
	{
		execve(commpath, command, NULL);
		perror("execve");
	}
	else if (cpid == -1)
		perror("fork");
	return (0);
}

char	*get_commpath(char *envp[], const char *command)
{
	char	**paths;
	int		i;
	char	*commpath;
	char	*saved_command;

	paths = get_paths(envp);
	saved_command = ft_strjoin("/", command);
	i = 0;
	while (paths[i++])
	{
		commpath = check_commpath(paths[i], saved_command);
		if (commpath)
		{
			i = 0;
			while (paths[i])
				free(paths[i++]);
			free(saved_command);
			return (commpath);
		}
		free(commpath);
	}
	ft_fprintf(2, "pipex: no such file or directory: ");
	ft_fprintf(2, "%s%s\n", paths[0], saved_command);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(saved_command);
	return (NULL);
}

char	*check_commpath(char *path, char *slashcomm)
{
	char	*commpath;

	commpath = ft_strjoin(path, slashcomm);
	if (!commpath)
		return (NULL);
	else if (access(commpath, X_OK) == 0)
	{
		free(slashcomm);
		return (commpath);
	}
	free(commpath);
	return (NULL);

}

char	**get_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!strncmp("PATH=", envp[i], 5))
		{
			return (ft_split(envp[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
}
