/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_scroll_o_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:57:03 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:50:22 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision_scroll_orb(t_data *data)
{
	if (aabb_scroll_orb(data, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)))
	{
		data->map.collectible--;
		data->player->got_items[1] = 1;
		return (1);
	}
	return (0);
}
