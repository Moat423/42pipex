/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:45:09 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/26 15:47:29 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft_full.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

//pipex_bonus.c
int		input_checker(int argc, char *arg);
int		pipheredoc(char *arg);
int		open_doc(char *file, int filekind);

//utils_bonus.c
char	*get_line(int fd);
int		here_doc(char *delim);

//utils.c
int		free_char_array(char **array, int ret);
int		rperror(char *str);

//path.c
char	*get_commpath(char *envp[], const char *command);
char	**get_paths(char *envp[]);
int		make_exec(char *arg, char *envp[]);
int		exec_to_stdout(char *arg, char **envp);
int		pipex(int argc, char **argv, char **envp, int curr);

//command.c
int		exec_to_stdout(char *arg, char **envp);
int		exec_command(char *command, char *envp[], int in_fd, int out_fd);
int		pipex(int argc, char **argv, char **envp, int curr);

#endif //PIPEX_BONUS_H
