/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:57:47 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/08 14:05:50 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 *DESCRIPTION
    The memmove() function copies len bytes from string src to string dst.
    The two strings may overlap; the copy is always done in a non-destructive
	manner.
RETURN VALUES
    The memmove() function returns the original value of dst.
 *
 * remember that I do not have to reassign c_dest to dest, because i just have
two pointers, dest is a void pointer to an address, c_dest is a char pointer
to the same address, so by modifying the content of one, i am modifying 
the content that both pointers point to, that is the reason i just return dest
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*c_dest;
	const char	*c_src;

	c_dest = (char *) dest;
	c_src = (const char *) src;
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	else if (src < dest)
	{
		i = n;
		while ((i != 0))
		{
			i--;
			c_dest[i] = c_src[i];
		}
	}
	return (dest);
}
