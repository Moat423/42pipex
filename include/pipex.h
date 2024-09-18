/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:37:12 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/18 16:53:32 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft_full.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h> //strerror
# include <fcntl.h>
# include <sys/wait.h>

int	get_fd(char *filename);
int	basic_argc_checking(int argc);

//utils.c
int	free_char_array(char **array, int ret);
int	ft_fprintf_char_array(int fd, char **array);

//path.c
int	execute(int argc, char *argv[], char *envp[]);
char	*get_commpath(char *envp[], const char *command);
char	*check_commpath(char *path, char *backslcomm);
char	**get_paths(char *envp[]);
int	make_exec(const char **command, char *commpath, int	fds[]);

#endif //PIPEX_H
