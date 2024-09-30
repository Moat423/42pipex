/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:16:43 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/10 17:46:12 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
RETURN
The string representing the integer.
NULL if the allocation fails.
VARS
n: the integer to convert.
*/

#include "libft.h"

static unsigned int	get_size(const int n)
{
	unsigned int	n_for_size;
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		size += 2;
		n_for_size = n / -10;
	}
	else if (n == 0)
		return (1);
	else
		n_for_size = n;
	while (n_for_size)
	{
		n_for_size /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	size;

	size = get_size(n);
	if (n == INT_MIN)
		return (num = ft_strdup("-2147483648"));
	num = (char *) malloc (size + 1);
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	num[size] = '\0';
	while (n)
	{
		num[--size] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}
