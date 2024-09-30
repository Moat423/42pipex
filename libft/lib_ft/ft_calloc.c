/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:26 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/07 20:11:37 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
 * The malloc() function allocates size bytes and returns a pointer to the 
 * allocated memory.  The memory is not initialized.  If size is 0, 
 * then malloc()  returns  either NULL,  or  a  unique
 * pointer value that can later be successfully passed to free().
RETURN
 The  malloc()  and calloc() functions return a pointer to the allocated 
 memory, which is suitably aligned for any built-in type.  On error, these 
 functions return NULL.  NULL may also  be returned by a successful call to
 malloc() with a size of zero, or by a successful call to calloc() with 
 nmemb or size equal to zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
