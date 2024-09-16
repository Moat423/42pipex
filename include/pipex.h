/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:37:12 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/16 10:05:24 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft_full.h"
# include <stdlib.h>
# include <unistd.h>

int	get_fd(char *filename);
int	invoke_command(int	infile);

#endif //PIPEX_H
