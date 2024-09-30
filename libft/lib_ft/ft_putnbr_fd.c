/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:46:40 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/13 13:20:36 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Outputs the integer ’n’ to the given file
descriptor.
allowed funcitons: write
VARS
n: The integer to output.
fd: The file descriptor on which to write.
*/

#include "libft.h"

void	convertwrite_fd(unsigned int n, int fd)
{
	char	num_buff;

	if (n >= 10)
		convertwrite_fd(n / 10, fd);
	num_buff = n % 10 + '0';
	write(fd, &num_buff, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pnum;

	if (n < 0)
	{
		write(fd, "-", 1);
		pnum = (unsigned int) -n;
	}
	else
		pnum = (unsigned int) n;
	convertwrite_fd(pnum, fd);
}
