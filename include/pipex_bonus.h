/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:45:09 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 11:56:00 by lmeubrin         ###   ########.fr       */
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
int	input_checker(int argc, char *arg);
int	pipheredoc(char *arg);

//utils.c
int		free_char_array(char **array, int ret);
int		ft_fprintf_char_array(int fd, char **array);
int		rperror(char *str);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);

//path.c
char	*get_commpath(char *envp[], const char *command);
char	**get_paths(char *envp[]);
int		make_exec(char *arg, char *envp[]);
int		exec_to_outf(char *arg, char **envp, int outfile);
int		pipex(char *arg, char **envp);

//utils_bonus.c
char	*get_line(int fd);
int		here_doc(char *delim);

#endif //PIPEX_BONUS_H
