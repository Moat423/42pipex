/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:47 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:39:49 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line = ft_substr_diff(buffer, *i + 1);
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
		buffer = (char *) gnl_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	init_len = bufferlen + BUFFER_SIZE + 1;
	save = ft_substr_diff(buffer, bufferlen);
	free(buffer);
	if (!save)
		return (NULL);
	buffer = gnl_calloc(init_len, 1);
	if (!buffer)
		return (NULL);
	gnl_strlcpy(buffer, save, init_len);
	free(save);
	return (buffer);
}

//makes and reads from fd into buffer until newline or EOF in buffer
char	*read_into( int fd, char *buffer)
{
	unsigned int	len;
	long long		readlen;

	readlen = 1;
	while (!gnl_strchr(buffer, '\n') && readlen > 0)
	{
		len = gnl_strlen(buffer);
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
	static char		*buffer = NULL;
	unsigned int	i;

	line = NULL;
	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	buffer = read_into(fd, buffer);
	if (!buffer)
		return (NULL);
	line = make_line(buffer, &i);
	if (i <= gnl_strlen(buffer))
		gnl_strlcpy(buffer, buffer + i + 1, gnl_strlen(buffer + i));
	if (buffer[0] == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
