/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:40:35 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/10 13:44:00 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_after_point(char *str)
{
	double	pos;
	double	res_b;

	pos = 1;
	res_b = 0;
	while (*str <= '9' && *str >= '0')
	{
		pos /= 10;
		res_b += pos * (*str - '0');
		str++;
	}
	return (res_b);
}

double	ft_atod(char *str)
{
	double	res_a;
	int		sign;
	double	res_b;

	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	res_a = 0;
	while (*str >= '0' && *str <= '9')
		res_a = res_a * 10 + *(str++) - '0';
	if (*(str++) != '.')
		return (res_a * sign);
	res_b = ft_after_point(str);
	return ((res_a + res_b) * sign);
}
