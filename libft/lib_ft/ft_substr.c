/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:16:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/08 13:42:24 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
 * Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’. 
PARAMETERS
    s: string from which to extract the new string
    start: start index of the new string in the string 's'
    len: maximum size of the new string
RETURN VALUES
    ft_substr() returns the new string; NULL if the memory allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
*/

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *) malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
