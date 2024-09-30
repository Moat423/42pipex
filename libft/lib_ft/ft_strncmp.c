/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:05:00 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/07 18:28:38 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
The strncmp() function lexicographically compare the null-terminated 
strings s1 and s2.
The strncmp() function compares not more than n characters. Because strncmp() 
is designed for comparing strings rather than binary data, characters that 
appear after a '\0' character are not compared.
RETURN VALUES
The strncmp() function returns an integer greater than, equal to, or less than
0, according as the string s1 is greater than, equal to, or less than the 
string s2. The comparison is done using unsigned characters, so that '\200' 
is greater than '\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	i = 0;
	cs1 = (const unsigned char *) s1;
	cs2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((i + 1 < n) && (cs1[i] == cs2[i]) && (cs1[i] && (cs2[i])))
		i++;
	return (cs1[i] - cs2[i]);
}
