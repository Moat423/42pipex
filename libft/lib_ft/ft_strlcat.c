/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:25 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/17 16:39:15 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
The strlcat() function concatenate strings with the same input parameters and 
outuput result as snprintf(3). It is designed to be safer, more consistent, and
less error prone replacements for the easily misused function strncat(3).
strlcat() take the full size of the destination buffer and guarantee 
NUL-termination if there is room. Note that room for the NUL should be included
in dstsize. Also note that strlcat() only operate on true ''C'' strings. This
means that both src and dst must be NUL-terminated.
strlcat() appends string src to the end of dst. It will append at most size
- strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is 0 
or the original dst string was longer than dstsize (in practice this should not
happen as it means that either dstsize is incorrect or that dst is not a proper
string). If the src and dst strings overlap, the behavior is undefinded.
RETURN VALUES
Like snprintf(3), strlcat() function return the total length of the string it 
tried to create. That means the initial length of dst plus the length of src.
If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (size + srclen);
	while (src[i] && ((destlen + i) < size - 1))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen + destlen);
}
