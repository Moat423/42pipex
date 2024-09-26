/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:37:12 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/26 15:46:19 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft_full.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

//pipex.c
int		basic_argc_checking(int argc);

//utils.c
int		free_char_array(char **array, int ret);
int		rperror(char *str);

//path.c
char	*get_commpath(char *envp[], const char *command);
char	**get_paths(char *envp[]);
int		make_exec(char *arg, char *envp[]);

//command.c
int		exec_to_stdout(char *arg, char **envp);
int		exec_command(char *command, char *envp[], int in_fd, int out_fd);
int		pipex(int argc, char **argv, char **envp, int curr);

#endif //PIPEX_H
