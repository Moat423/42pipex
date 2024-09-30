/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:37:37 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/06/06 10:37:39 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlcpy(char *dest, char *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (!dest)
		return (-1);
	if (len == 0)
	{
		dest[0] = '\0';
		return (ft_strlen(src));
	}
	while (src[i] && (i + 1) < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
		dest[i++] = '\0';
	return (ft_strlen(dest));
}

//returns length of str or 0 if no str
unsigned long	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

//find c in str, return pointer to c in str
char	*ft_strchr(char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *src, unsigned int len)
{
	char			*dest;
	unsigned int	i;

	if (!src)
		return (NULL);
	i = 0;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t size, size_t nmemb)
{
	void			*ptr;
	char			*strptr;
	unsigned int	i;

	i = 0;
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	strptr = ptr;
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		*(strptr + i++) = '\0';
	}
	return (ptr);
}
