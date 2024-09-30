/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:23 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/10 13:55:13 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* in case i am not supposed to return 1 and two but the value the function
* spits out, change the return to 1024 for both, even though it is defined
* as returning a non-negative value if its a letter*/

int	ft_isalpha(int c)
{
	if ((c <= 'Z') && (c >= 'A'))
		return (1024);
	else if ((c <= 'z') && (c >= 'a'))
		return (1024);
	return (0);
}
