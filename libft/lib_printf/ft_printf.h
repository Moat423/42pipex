/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:02:32 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/16 14:17:38 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putunbr_fd(unsigned int n, int fd, int *count);
int	ft_putnbr_fd_return(int n, int fd);
int	ft_putptr_fd(void *nb, int fd);
int	ft_puthex_fd(unsigned long nb, int fd, int *count, char *base);
int	ft_puthex_lower_fd(unsigned long nb, int fd, int *count);
int	ft_puthex_upper_fd(unsigned int nb, int fd, int *count);
int	ft_putchar_fd_return(char c, int fd);
int	ft_putstr_fd_return(char *s, int fd);
int	string_iteration(const char *str, va_list args);
#endif
