/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:06:52 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/08 17:20:20 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION */
/* Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *) malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len1 + 1);
	ft_strlcpy(joined_str + len1, s2, len2 + 1);
	joined_str[len1 + len2 + 1] = '\0';
	return (joined_str);
}
