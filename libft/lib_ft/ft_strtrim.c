/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:53:19 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/10 17:12:29 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
 RETURN:
The trimmed string.
NULL if the allocation fails.
 VARS:
s1: The string to be trimmed.
set: The reference set of characters to trim.
strimm: the trimmed output string.
*/

#include "libft.h"
#include <stdio.h>

static size_t	get_back_i(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	back_i;

	back_i = 0;
	if (!s1[0])
		return (0);
	i = ft_strlen(s1) - 1;
	while (i != 0 && (ft_strchr(set, s1[i]) != NULL))
	{
		i--;
		back_i++;
	}
	return (back_i);
}

static char	*get_start(char const *s1, char const *set)
{
	while (*s1 && (ft_strchr(set, *s1) != NULL))
		s1++;
	return ((char *) s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	char	*start;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	if (ft_strlen(start) != 0)
		size = ft_strlen(start) - get_back_i(s1, set);
	else
		size = 0;
	strim = (char *) malloc(size + 1);
	if (strim == NULL)
		return (NULL);
	if (size == 0)
		strim[0] = '\0';
	else
		ft_strlcpy(strim, start, size + 1);
	return (strim);
}
