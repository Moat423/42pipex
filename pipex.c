/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/14 18:08:27 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/lib_printf/ft_printf.h"

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);

int	main(int argc, char *argv[])
{
	int	infile;

	if (argc == 1)
		ft_printf("pipex: parse error");
	if (argc > 5)
		ft_printf("pipex: ecxess argument(s)");
	infile = get_fd(argv[1]);
	for (int i = 0; i < argc; i++)
	{
		ft_printf("Argument %d: %s\n", i, argv[i]);
	}
	return (EXIT_SUCCESS);
}

int	get_fd(char *filename)
{
	int	acc;
	int	fd;

	if (filename && filename[0])
	{
		if (access(filename, F_OK) == -1)
		{
			ft_printf("pipex: no such file or directory:\n0");
			return (0);
		}
		//read permissions
		//are there commands that require different permissions?
	}
	return (fd);
}
