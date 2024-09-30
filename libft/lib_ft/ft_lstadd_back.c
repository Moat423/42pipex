/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:24:23 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/17 17:59:14 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION
Adds the node ’new’ at the end of the list.
VARS
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*tmp;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		(*lst) = new_node;
	}
	else
	{
		tmp = *lst;
		while ((tmp)->next)
			(tmp) = (tmp)->next;
		(tmp)->next = new_node;
	}
}
/*
{
	t_list	*last_node;

	if (!(*lst))
		return ;
	if (lst)
	{
		last_node = ft_lstlast(*lst);
		if (!last_node)
			last_node = new_node;
		else
			last_node->next = new_node;
	}
}
*/
