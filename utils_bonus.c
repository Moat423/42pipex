/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:14:14 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/24 15:19:56 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	here_doc(char *delim)
{
	char	*line;
	int		delim_len;

	delim_len = ft_strlen(delim);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(delim, line, delim_len) && \
			(line[delim_len] == '\n' || line[delim_len] == '\0'))
		{
			free(line);
			line = get_next_line(-1);
			break ;
		}
		ft_fprintf(STDOUT_FILENO, "%s", line);
		free(line);
	}
	close (STDIN_FILENO);
	return (1);
}
