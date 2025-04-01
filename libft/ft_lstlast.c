/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:25:31 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/07 14:10:31 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst)
		return (NULL);
	tmp = lst;
	last = lst;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
			last = last->next;
	}
	return (last);
}
