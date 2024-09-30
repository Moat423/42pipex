/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:01:35 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/04/26 15:34:17 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
    the memchr() function locates the first occurence of c (convered to an 
	unsigned char) in string s.
RETURN VALUES
    The memchr() function returns a pointer to the byte located, or NULL if no
	such byte exists within n bytes.
VARS
s: string to search
c: character to find
n: ammount of characters to search
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((*(unsigned char *) s) == ((unsigned char) c))
			return ((void *) s);
		++s;
		n--;
	}
	return (NULL);
}
