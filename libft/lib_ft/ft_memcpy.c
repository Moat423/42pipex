/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:39:21 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/04/23 16:32:37 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
The memcpy() function copies n bytes from memory area src to memory area dest. 
The memory areas must not overlap.  
Use memmove(3) if the memory areas do overlap.

RETURN VALUE
The memcpy() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cdest;
	const char	*csrc;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (dest);
	cdest = (char *) dest;
	csrc = (const char *) src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
