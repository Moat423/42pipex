/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:44:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/02 14:51:03 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//writes char and returns sucess or not
int	ft_putchar_fd_return(char c, int fd)
{
	return (write(fd, &c, 1));
}

//writes string and return chars written or null for invalid s
int	ft_putstr_fd_return(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

//writes an int number with - and returns chars written
int	ft_putnbr_fd_return(int n, int fd)
{
	unsigned int	pnum;
	int				count;

	count = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		pnum = (unsigned int) -n;
		count += 1;
	}
	else
		pnum = (unsigned int) n;
	ft_putunbr_fd(pnum, fd, &count);
	return (count);
}
