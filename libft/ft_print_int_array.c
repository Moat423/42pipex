/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:35:28 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/10 10:44:57 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

void	ft_printf_int_array(const int *array, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("n%d: %i\n", i, array[i]);
		i++;
	}
}
