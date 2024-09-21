/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:51:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/21 19:22:44 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	free_char_array(char **array, int ret)
{
	int	i;

	i = 0;
	if (!array)
		return (ret);
	while (array[i])
		free(array[i++]);
	free(array);
	return (ret);
}

int	ft_fprintf_char_array(int fd, char **array)
{
	int	count;

	count = 0;
	while (*array)
	{
		count += ft_fprintf(fd, "%s", (*array));
		write(fd, "\n", 1);
		++array;
	}
	write(fd, "\n", 1);
	return (count);
}

int	rperror(char *str)
{
	perror(str);
	return (EXIT_FAILURE);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	char	*joined_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	joined_str = (char *) malloc(len1 + len2 + len3 + 1);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len1 + 1);
	ft_strlcpy(joined_str + len1, s2, len2 + 1);
	ft_strlcpy(joined_str + len1 + len2, s3, len3 + 1);
	joined_str[len1 + len2 + len3] = '\0';
	return (joined_str);
}
