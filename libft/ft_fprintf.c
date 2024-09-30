/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:54 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/24 14:58:55 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_full.h"

int	ft_fprintf(const int fd, const char *str, ...)
{
	int		chars_written;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (-1);
	chars_written = fstring_iteration(fd, str, args);
	va_end(args);
	return (chars_written);
}

int	fstring_iteration(const int fd, const char *str, va_list args)
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
			conversion_out = fconversion_specs(fd, str + ++i, args);
			if (conversion_out >= 0)
			{
				counter += conversion_out;
				i++;
			}
			else if (conversion_out < 0)
				return (conversion_out);
		}
		else
			counter += write(fd, &str[i++], 1);
	}
	return (counter);
}

int	fconversion_specs(const int fd, const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = ft_putchar_fd_return(va_arg(args, int), fd);
	else if (*str == 's')
		count = ft_putstr_fd_return(va_arg(args, char *), fd);
	else if (*str == 'p')
		count = ft_putptr_fd(va_arg(args, void *), fd);
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr_fd_return(va_arg(args, int), fd);
	else if (*str == 'u')
		count = ft_putunbr_fd(va_arg(args, int), fd, &count);
	else if (*str == 'x')
		count = ft_puthex_lower_fd(va_arg(args, unsigned int), fd, &count);
	else if (*str == 'X')
		count = ft_puthex_upper_fd(va_arg(args, int), fd, &count);
	else if (*str == '\0')
		return (-1);
	else if (*str == '%')
		return (write(1, "%", fd));
	return (count);
}
