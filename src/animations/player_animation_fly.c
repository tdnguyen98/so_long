/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_fly.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:42:12 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:44:01 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_fly(t_data *data)
{
	data->steps++;
	if (data->player->direction == 0)
		animation_fly_right(data);
	else
		animation_fly_left(data);
}

void	animation_fly_right(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 12)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[12 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 24)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[13 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 36)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[14 + data->player->anim_staff_offset],
			512, 512);
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[12 + data->player->anim_staff_offset],
			512, 512);
	}
}

void	animation_fly_left(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 12)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[15 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 24)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[16 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 36)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[17 + data->player->anim_staff_offset],
			512, 512);
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[15 + data->player->anim_staff_offset],
			512, 512);
	}
}
