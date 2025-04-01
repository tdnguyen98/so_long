/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:24:16 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:26:19 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trap(t_data *data)
{
	t_trap	*trap;

	trap = data->map.trap;
	while (trap != NULL)
	{
		if (aabb_trap(data, trap, (data->player->pos[0] - 512),
				(data->player->pos[1] - 512)))
		{
			trap->is_triggered = 1;
			if (trap->delay >= 50)
				data->player->life_points -= 30;
		}
		if (trap->is_triggered == 0)
			draw_tile_trap(data, trap->pos[0] - (data->player->pos[0] - 512),
				trap->pos[1] - (data->player->pos[1] - 512), trap->dir);
		else if (trap->is_triggered == 1 && trap->delay <= 50)
			draw_tile_trap(data, trap->pos[0] - (data->player->pos[0] - 512),
				trap->pos[1] - (data->player->pos[1] - 512), trap->dir + 1);
		else if (trap->is_triggered == 1 && trap->delay > 50)
			draw_tile_trap(data, trap->pos[0] - (data->player->pos[0] - 512),
				trap->pos[1] - (data->player->pos[1] - 512), trap->dir + 2);
		trap = trap->next;
	}
}
