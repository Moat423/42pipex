/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/15 09:21:43 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
     The strlcpy() function copies strings.
     strlcpy()takes the full size of the buffer
     (not just the length) and guarantee to NUL-terminate the result 
	 (as long as size is larger than 0 or, in the case of strlcat(), as long
	 as there is at least one byte free in dst).  Note that a byte for the NUL
	 should be included in size.  Also note that strlcpy() and strlcat() only 
	 operate on true “C” strings.  This means that for strlcpy() src must be 
	 NUL-terminated and for strlcat() both src and dst must be NUL-terminated.

     The strlcpy() function copies up to size - 1 characters from the 
	 NUL-terminated string src to dst, NUL-terminating the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the string
	 they tried to create.  For strlcpy() that means the length of src.
     this may seem somewhat confusing, it was done to make truncation 
	 detection simple.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (((i + 1) < size) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
