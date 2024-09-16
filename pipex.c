/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/16 19:55:16 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <stdlib>

// todo
//do something for first letter of filename == | as per man open

int	get_fd(char *filename);
int	handle_command(int infile, int argc, char *commands[]);
int	invoke_command(int *pipes, char *command);

int	main(int argc, char *argv[])
{
	int	infile;
	int	command;
	int	outfile;

	errno = 0;
	if (basic_argc_checking(argc))
		return (EXIT_FAILURE);
	infile = get_fd(argv[1]);
	outfile = open(argv[argc - 1], O_TRUNC, O_CLOEXEC, O_CREAT, 00666);
	//if infile invalid (error) then proceed with the second command
	command = handle_command(infile, argv);
	return (EXIT_SUCCESS);
}

int	handle_command(int infile, int argc, char *commands[])
{
	int 	i;
	char	*command;
	int		fds_command1[2];

	i = 0;
	command = NULL;
	while (i < argc - 1)
	{
		command = commands[i + 1];
		if (pipe(fds_command1) == -1)
			ft_fprintf(2, "%s", strerror(errno));
		if (invoke_command(fds_command1, command) == -1)
			return (1);
	}
	if (fork() == 0)

	return (0);
}


int	invoke_command(int *pipes, char *command)
{
	
}

int	basic_argc_checking(int argc)
{
	if (argc == 1)
		ft_printf("pipex: parse error");
	if (argc > 5)
		ft_printf("pipex: ecxess argument(s)");
	if (argc == 1 || argc > 5)
		return (1);
	return (0);
}

int	get_fd(char *filename)
{
	int	acc;
	int	fd;

	if (!filename)
		return (-1);
	if (access(filename, F_OK) == -1)
	{
		ft_fprintf(2, "pipex: no such file or directory: %s\n", filename);
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		ft_fprintf(2, "pipex: permission denied: nopermission\n");
		return (-1);
	}
	fd = open(filename, O_CLOEXEC);
	//mkdir and others need write permission!
	return (fd);
}
