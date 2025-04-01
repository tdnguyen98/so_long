/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_trap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:06:04 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:55:28 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back_trap(t_trap **lst, t_trap *new)
{
	t_trap	*back;

	if (!new)
		return ;
	back = ft_lstlast_trap(*lst);
	if (!*lst)
		*lst = new;
	else
		back->next = new;
}

t_trap	*ft_lstlast_trap(t_trap *lst)
{
	t_trap	*tmp;
	t_trap	*last;

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
