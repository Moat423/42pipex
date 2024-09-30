/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_char_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:24:08 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 17:24:28 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

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
