/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:51:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/19 09:31:47 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//make a return exit failur perror function
 
#include "include/pipex.h"
#include "libft/libft_full.h"

int	free_char_array(char **array, int ret)
{
	int	i;

	i = 0;
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
