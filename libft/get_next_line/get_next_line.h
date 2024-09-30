/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:28:08 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:09:11 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif //BUFFER_SIZE

char			*get_next_line(int fd);
char			*gnl_strchr(const char *s, int c);
int				gnl_strlcpy(char *dst, char *src, unsigned int len);
unsigned long	gnl_strlen(const char *s);
char			*make_line(char *buffer, unsigned int *i);
char			*ft_substr_diff(char *src, unsigned int len);
char			*ft_realloc(char *buffer, unsigned int start);
char			*read_into( int fd, char *buffer);
void			*gnl_calloc(size_t count, size_t size);
#endif //GET_NEXT_LINE_H
