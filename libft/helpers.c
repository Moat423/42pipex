/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:14:50 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/10 10:45:26 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

//finds index of nb in list, -1 if nb not in list
int	ft_index_of_nb(int nb, int *list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (list[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_index_of_max(int *list, int len)
{
	int	i;
	int	max;

	max = ft_max_of_lst(list, len);
	i = 0;
	while (i < len)
	{
		if (list[i] == max)
			return (i);
		i++;
	}
	return (i);
}

int	ft_index_of_min(int *list, int len)
{
	int	i;
	int	min;

	min = ft_min_of_lst(list, len);
	i = 0;
	while (i < len)
	{
		if (list[i] == min)
			return (i);
		i++;
	}
	return (i);
}

int	ft_min_of_lst(int *list, int len)
{
	int	i;
	int	min;

	i = 1;
	min = list[0];
	while (i < len)
	{
		if (list[i] < min)
			min = list[i];
		i++;
	}
	return (min);
}

int	ft_max_of_lst(int *list, int len)
{
	int	i;
	int	max;

	i = 1;
	max = list[0];
	while (i < len)
	{
		if (list[i] > max)
			max = list[i];
		i++;
	}
	return (max);
}
