/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_idle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:42:18 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:44:36 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_idle(t_data *data)
{
	if (data->player->direction == 0)
	{
		data->player->anim_delay++;
		if (data->player->anim_delay <= 25)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.player[0 + data->player->anim_staff_offset],
				512, 512);
		else if (data->player->anim_delay <= 50)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.player[1 + data->player->anim_staff_offset],
				512, 512);
		}
		else
		{
			data->player->anim_delay = 0;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.player[0 + data->player->anim_staff_offset],
				512, 512);
		}
	}
	else
		animation_mirror(data);
}

void	animation_mirror(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[2 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 50)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[3 + data->player->anim_staff_offset],
			512, 512);
	}
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[2 + data->player->anim_staff_offset],
			512, 512);
	}
}
