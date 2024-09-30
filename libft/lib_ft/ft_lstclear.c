/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:09 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/17 17:35:30 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (lst && del)
	{
		while (*lst)
		{
			current = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = current;
		}
	}
}
