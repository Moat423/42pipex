/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:37:12 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 12:39:47 by lmeubrin         ###   ########.fr       */
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
int		pipex(char *arg, char **envp);

//utils.c
int		free_char_array(char **array, int ret);
int		ft_fprintf_char_array(int fd, char **array);
int		rperror(char *str);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);

//path.c
char	*get_commpath(char *envp[], const char *command);
int		exec_to_stdout(char *arg, char **envp);
char	**get_paths(char *envp[]);
int		make_exec(char *arg, char *envp[]);
int		pipex(char *arg, char **envp);

#endif //PIPEX_H
