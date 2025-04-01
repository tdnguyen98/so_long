/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_foe_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:31:59 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 11:38:34 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back_foe(t_foe **lst, t_foe *new)
{
	t_foe	*back;

	if (!new)
		return ;
	back = ft_lstlast_foe(*lst);
	if (!*lst)
		*lst = new;
	else
		back->next = new;
}

t_foe	*ft_lstlast_foe(t_foe *lst)
{
	t_foe	*tmp;
	t_foe	*last;

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
