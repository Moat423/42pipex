/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:54:42 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/10 10:49:10 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	buffer;
	int	j;

	i = 1;
	while (i < size)
	{
		buffer = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > buffer)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = buffer;
		i++;
	}
}

// use insertion sort to sort list and return a new malloced list
int	*ft_insertion_sort_int_list(const int *list, const int listlen)
{
	int	j;
	int	*sorted_list;

	sorted_list = malloc(listlen * sizeof(int));
	if (!sorted_list)
		return (NULL);
	j = 0;
	while (j < listlen)
	{
		sorted_list[j] = list[j];
		j++;
	}
	ft_sort_int_tab(sorted_list, listlen);
	return (sorted_list);
}
