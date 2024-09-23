/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:51:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 17:30:39 by lmeubrin         ###   ########.fr       */
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

int	rperror(char *str)
{
	perror(str);
	return (EXIT_FAILURE);
}
