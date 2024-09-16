/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/16 10:05:32 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/lib_printf/ft_printf.h"
#include <fcntl.h>

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);

int	main(int argc, char *argv[])
{
	int	infile;
	int	command;

	if (argc == 1)
		ft_printf("pipex: parse error");
	if (argc > 5)
		ft_printf("pipex: ecxess argument(s)");
	infile = get_fd(argv[1]);
	//if infile invalid (error) then proceed with the second command
	command = invoke_command(infile);
	for (int i = 0; i < argc; i++)
		ft_printf("Argument %d: %s\n", i, argv[i]);
	return (EXIT_SUCCESS);
}

int	invoke_command(int	infile)
{

}

int	get_fd(char *filename)
{
	int	acc;
	int	fd;

	if (!filename)
		return (-1);
	if (access(filename, F_OK) == -1)
	{
		ft_printf("pipex: no such file or directory: %s\n", filename);
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		ft_printf("pipex: permission denied: nopermission\n");
		return (-1);
	}
	fd = open(filename, O_CLOEXEC);
	//mkdir and others need write permission!
	return (fd);
}
