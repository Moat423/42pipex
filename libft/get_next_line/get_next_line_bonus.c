/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:36:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:06 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// allocates and writes line ending with null byte
char	*make_line(char *buffer, unsigned int *i)
{
	char			*line;

	line = NULL;
	*i = 0;
	if (!buffer[*i])
		return (NULL);
	while (buffer[*i] && buffer[*i] != '\n')
		++*i;
	if (!buffer[*i] || buffer[*i] == '\n')
		line = ft_substr(buffer, *i + 1);
	if (line)
		return (line);
	return (NULL);
}

//reallocates memory exponentially bigger than str,
char	*ft_realloc(char *buffer, unsigned int bufferlen)
{
	char			*save;
	unsigned int	init_len;

	save = NULL;
	if (!buffer)
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	init_len = bufferlen + BUFFER_SIZE + 1;
	save = ft_substr(buffer, bufferlen);
	if (!save)
		return (NULL);
	free(buffer);
	buffer = ft_calloc(init_len, 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, save, init_len);
	free(save);
	return (buffer);
}

//makes and reads from fd into buffer until newline or EOF in buffer
char	*read_into( int fd, char *buffer)
{
	unsigned int	len;
	long long		readlen;

	readlen = 1;
	while (!ft_strchr(buffer, '\n') && readlen > 0)
	{
		len = ft_strlen(buffer);
		buffer = ft_realloc(buffer, len);
		if (!buffer)
			return (NULL);
		readlen = read(fd, buffer + len, BUFFER_SIZE);
		if (readlen < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len + readlen] = '\0';
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer[1024] = {NULL};
	unsigned int	i;

	line = NULL;
	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
	{
		while (i < 1024)
			free(buffer[i++]);
		return (NULL);
	}
	buffer[fd] = read_into(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = make_line(buffer[fd], &i);
	if (i <= ft_strlen(buffer[fd]))
		ft_strlcpy(buffer[fd], buffer[fd] + i + 1, ft_strlen(buffer[fd] + i));
	if (buffer[fd][0] == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
