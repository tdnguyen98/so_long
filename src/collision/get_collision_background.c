/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_background.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:03:25 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:03:49 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_collision(t_data *data, int x, int y, int type)
{
	t_collision	*no_zone;

	no_zone = malloc(sizeof(t_collision));
	if (!no_zone)
		return ;
	no_zone->collision_type[0] = 0;
	no_zone->collision_type[1] = 0;
	no_zone->collision_type[2] = 0;
	no_zone->collision_type[3] = 0;
	no_zone->top_left[0] = x;
	no_zone->top_left[1] = y;
	no_zone->top_right[0] = x + 256;
	no_zone->top_right[1] = y;
	no_zone->bottom_left[0] = x;
	no_zone->bottom_left[1] = y + 256;
	no_zone->bottom_right[0] = x + 256;
	no_zone->bottom_right[1] = y + 256;
	no_zone->collision_type[type] = 1;
	no_zone->next = NULL;
	ft_lstadd_back_collision(&data->collision, no_zone);
}

void	ft_lstadd_back_collision(t_collision **lst, t_collision *new)
{
	t_collision	*back;

	if (!new)
		return ;
	back = ft_lstlast_collision(*lst);
	if (!*lst)
		*lst = new;
	else
		back->next = new;
}

t_collision	*ft_lstlast_collision(t_collision *lst)
{
	t_collision	*tmp;
	t_collision	*last;

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
