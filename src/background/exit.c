/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:23 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:38:46 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_data *data)
{
	if (aabb_exit(data, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)) && data->map.collectible <= 0)
	{	
		if (data->ending[0] == 0)
			data->ending[0] = 1;
		data->ending[2] = 1;
	}
	else
		draw_tile_exit(data, data->map.exit->pos[0]
			- (data->player->pos[0] - 512),
			data->map.exit->pos[1] - (data->player->pos[1] - 512));
}

void	draw_tile_exit(t_data *data, int x, int y)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900
		|| data->map.collectible > 9)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.exit[data->map.collectible], x, y);
}
