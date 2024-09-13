/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/13 09:57:40 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	main(int argc, char *argv[])
{
	ft_printf("Number of arguments: %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		ft_printf("Argument %d: %s\n", i, argv[i]);
	}
	return (EXIT_SUCCESS);
}
