/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:27:03 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/09/23 13:33:02 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//find first occurance of substr in str
char	*ft_strstr(char *str, char *substr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !substr)
		return (0);
	if (!*substr)
		return (str);
	while (str[i])
	{
		while (substr[j] && str[i + j] == substr[j])
			j++;
		if (!substr[j])
			return (&str[i]);
		i++;
	}
	return (0);
}
