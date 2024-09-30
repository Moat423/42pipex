/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:47:31 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/10 21:00:12 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
RETURN
The array of new strings resulting from the split.
NULL if the allocation fails.
VARS
s: The string to be split.
c: The delimiter character.
*/

#include "libft.h"

unsigned int	count_words(const char *s, char c)
{
	int				words;
	unsigned int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i]))
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

unsigned int	wordsize(const char *s, char c)
{
	unsigned int	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static void	make_free(char **sarr, int i)
{
	while (i >= 0)
		free(sarr[i--]);
	free(sarr);
}

char	**fill_array(const char *s, char c, char **sarr)
{
	size_t			arr_i;
	int				i;
	unsigned int	size;

	i = 0;
	arr_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		size = wordsize(&s[i], c);
		if (size)
		{
			sarr[arr_i] = ft_substr(&s[i], 0, size);
			if (sarr[arr_i] == NULL)
			{
				make_free(sarr, arr_i - 1);
				return (NULL);
			}
			i += size;
			arr_i++;
		}
	}
	sarr[arr_i] = NULL;
	return (sarr);
}

char	**ft_split(char const *s, char c)
{
	char			**sarr;

	if (!s)
		return (NULL);
	sarr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!sarr)
		return (NULL);
	if (!fill_array(s, c, sarr))
		return (NULL);
	return (sarr);
}
