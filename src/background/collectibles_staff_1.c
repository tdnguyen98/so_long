/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_staff_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:38:32 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 23:18:50 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_staff(t_data *data)
{
	if (data->map.staff->staff == 1)
	{
		move_staff(data);
		if (check_collision_staff(data))
			data->map.staff->staff = 0;
	}
	draw_tile_staff(data, data->map.staff->pos[0]
		- (data->player->pos[0] - 512),
		data->map.staff->pos[1] - (data->player->pos[1] - 512));
	draw_tile_base_staff(data, data->map.staff->pos_base[0]
		- (data->player->pos[0] - 512),
		data->map.staff->pos_base[1] - (data->player->pos[1] - 512));
}

void	draw_tile_staff(t_data *data, int x, int y)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900
		|| data->map.staff->staff == 0)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.collectible[2], x, y);
}

void	draw_tile_base_staff(t_data *data, int x, int y)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900)
		return ;
	if (data->map.staff->staff == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collectible[4], x, y);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collectible[3], x, y);
}

void	move_staff(t_data *data)
{
	data->map.staff->staff_offset = (data->map.staff->staff_offset + 1) % 80;
	if (data->map.staff->staff_offset < 40)
		data->map.staff->pos[1] += 1;
	else
		data->map.staff->pos[1] -= 1;
	new_collision_staff(data);
}

void	new_collision_staff(t_data *data)
{
	data->map.staff->pos_top_left[0] = data->map.staff->pos[0] + 100;
	data->map.staff->pos_top_left[1] = data->map.staff->pos[1] + 85;
	data->map.staff->pos_top_right[0] = data->map.staff->pos[0] + 148;
	data->map.staff->pos_top_right[1] = data->map.staff->pos[1] + 85;
	data->map.staff->pos_bottom_left[0] = data->map.staff->pos[0] + 100;
	data->map.staff->pos_bottom_left[1] = data->map.staff->pos[1] + 178;
	data->map.staff->pos_bottom_right[0] = data->map.staff->pos[0] + 148;
	data->map.staff->pos_bottom_right[1] = data->map.staff->pos[1] + 178;
}
