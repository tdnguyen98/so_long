/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_run.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:33:07 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:46:40 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_run(t_data *data)
{
	data->steps++;
	if (data->player->direction == 0)
		animation_run_right(data);
	else
		animation_run_left(data);
}

void	animation_run_right(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 12)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[4 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 24)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[5 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 36)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[6 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 48)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[7 + data->player->anim_staff_offset],
			512, 512);
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[4 + data->player->anim_staff_offset],
			512, 512);
	}
}

void	animation_run_left(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 12)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[8 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 24)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[9 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 36)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[10 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 48)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[11 + data->player->anim_staff_offset],
			512, 512);
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[8 + data->player->anim_staff_offset],
			512, 512);
	}
}
