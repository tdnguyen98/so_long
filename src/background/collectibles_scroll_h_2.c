/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_scroll_h_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:03:14 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:50:28 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision_scroll_heal(t_data *data)
{
	if (aabb_scroll_heal(data, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)))
	{
		data->map.collectible--;
		data->player->got_items[2] = 1;
		return (1);
	}
	return (0);
}
