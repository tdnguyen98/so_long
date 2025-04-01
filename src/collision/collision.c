/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:47:36 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:41:16 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision(t_data *data, int dir)
{
	t_collision	*first;
	static char	direction[5] = {'l', 'r', 'u', 'd', 'g'};
	int			count;

	count = 15;
	first = data->collision;
	while (first != NULL)
	{
		if (aabb(data, first, direction[dir], 5) < count)
			count = aabb(data, first, direction[dir], 5);
		first = first->next;
	}
	return (count);
}
