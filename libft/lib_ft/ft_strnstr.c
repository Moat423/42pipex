/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:20:55 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/06 10:28:18 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
The strnstr() function locates the first occurence of the null-terminated 
string needle in the string haystack, where not more than len characters are 
searched. Characters that appear after a '\0' character are not searched.
RETURN VALUES
If needle is an empty string, haystack is returned; if needle occurs nowhere 
in haystack, NULL is returned; otherwise a pointer to the first character of 
the first occurence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *) s);
	while ((s[i]) && (i < len))
	{
		j = 0;
		while (i + j < len && s[i + j] && needle[j] && s[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *) &(s[i]));
		i++;
	}
	return (NULL);
}
