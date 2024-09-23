/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:14:14 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 18:14:51 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

// replace with get_next_line and make EOF work only when first word of newline
char	*get_line(int fd)
{
	char	*str;
	int		i;
	int		read_ret;

	i = 0;
	str = ft_calloc(1, 520);
	if (!str)
		return (0);
	while ((str[i] == '\n' || str[i] == '\0'))
	{
		read_ret = read(fd, &str[i], 1);
		if (read_ret == -1)
			return (0);
		else if (read_ret == 0)
			break ;
		if (i++ == 519)
		{
			ft_fprintf(2, "sign limit reached, i = %d\n", i);
			break ;
		}
	}
	return (str);
}

int	here_doc(char *delim)
{
	char	*line;
	char	*delim_start;

	line = get_line(0);
	while (line)
	{
		delim_start = ft_strstr(line, delim);
		if (delim_start)
		{
			ft_bzero(delim_start, ft_strlen(delim_start));
			ft_fprintf(1, "%s\n", line);
			break ;
		}
		ft_fprintf(1, "%s\n", line);
		free(line);
		line = get_line(0);
	}
	free(line);
	return (1);
}
