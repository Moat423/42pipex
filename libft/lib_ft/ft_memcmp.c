/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:13:55 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/14 13:30:28 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
    The  memcmp()  function  compares the first n bytes (each interpreted
	as unsigned char) of the memory areas s1 and s2.
RETURN VALUES
The memcmp() function returns zero if the two strings are identical, 
otherwise returns the difference betwee the first two differing bytes 
(treated as unsigned char values, so that '\200' is greater than '\0',
for example).
Zero-length strings are always identical. This behaviour is not required 
by C and portable code should only depend on the sign of the returned value.
VARS
s1: string one
s2: string two to compare
n: bytes to read
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;

	c_s1 = (const unsigned char *) s1;
	c_s2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*c_s1 != *c_s2)
			return (*c_s1 - *c_s2);
		c_s1++;
		c_s2++;
	}
	return (0);
}
