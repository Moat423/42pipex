/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:30:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:15:21 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlcpy(char *dst, char *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (!dst)
		return (-1);
	if (len == 0)
	{
		dst[0] = '\0';
		return (gnl_strlen(src));
	}
	while (src[i] && (i + 1) < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (gnl_strlen(dst));
}

//returns length of str or 0 if no str
unsigned long	gnl_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

//find c in str, return pointer to c in str
char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr_diff(char *src, unsigned int len)
{
	char			*dest;
	unsigned int	i;

	dest = NULL;
	if (!src)
		return (NULL);
	i = 0;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	gnl_strlcpy(dest, src, len);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*strptr;
	size_t			i;

	ptr = NULL;
	i = 0;
	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	strptr = (unsigned char *)ptr;
	while (i < (count * size))
	{
		*(strptr + i++) = 0;
	}
	return (ptr);
}
