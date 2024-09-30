/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:35:46 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/10 10:44:54 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

//while loop to print out charlist to test it
void	ft_printf_char_array(char *const *array, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("n%d: %s\n", i, array[i]);
		i++;
	}
}
