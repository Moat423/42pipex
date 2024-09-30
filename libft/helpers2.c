/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:55:28 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/28 08:58:03 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// if there is a duplicate number in list, return position of the dup, else 0
int	ft_find_dup(int *list, int listlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < listlen)
	{
		j = i + 1;
		while (j < listlen)
		{
			if (list[i] == list[j])
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}
