/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:25:01 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 13:25:13 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back_collect(t_collect **lst, t_collect *new)
{
	t_collect	*back;

	if (!new)
		return ;
	back = ft_lstlast_collect(*lst);
	if (!*lst)
		*lst = new;
	else
		back->next = new;
}

t_collect	*ft_lstlast_collect(t_collect *lst)
{
	t_collect	*tmp;
	t_collect	*last;

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
