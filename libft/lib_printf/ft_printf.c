/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:03:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/02 14:52:06 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_specs(const char *str, va_list args)
{
	int		count;

	count = 0;
	if (*str == 'c')
		count = ft_putchar_fd_return(va_arg(args, int), 1);
	else if (*str == 's')
		count = ft_putstr_fd_return(va_arg(args, char *), 1);
	else if (*str == 'p')
		count = ft_putptr_fd(va_arg(args, void *), 1);
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr_fd_return(va_arg(args, int), 1);
	else if (*str == 'u')
		count = ft_putunbr_fd(va_arg(args, int), 1, &count);
	else if (*str == 'x')
		count = ft_puthex_lower_fd(va_arg(args, unsigned int), 1, &count);
	else if (*str == 'X')
		count = ft_puthex_upper_fd(va_arg(args, int), 1, &count);
	else if (*str == '\0')
		return (-1);
	else if (*str == '%')
		return (write(1, "%", 1));
	return (count);
}

//returns characters written
int	string_iteration(const char *str, va_list args)
{
	int		i;
	int		counter;
	int		conversion_out;

	i = 0;
	counter = 0;
	conversion_out = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			conversion_out = conversion_specs(str + ++i, args);
			if (conversion_out >= 0)
			{
				counter += conversion_out;
				i++;
			}
			else if (conversion_out < 0)
				return (conversion_out);
		}
		else
			counter += write(1, &str[i++], 1);
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		chars_written;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (-1);
	chars_written = string_iteration(str, args);
	va_end(args);
	return (chars_written);
}
