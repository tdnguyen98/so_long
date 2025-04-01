/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_falling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:42:06 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:42:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_fall(t_data *data)
{
	data->player->anim_delay++;
	if (data->player->anim_delay <= 12)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[19 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 24)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[20 + data->player->anim_staff_offset],
			512, 512);
	else if (data->player->anim_delay <= 36)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[21 + data->player->anim_staff_offset],
			512, 512);
	else
	{
		data->player->anim_delay = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[19 + data->player->anim_staff_offset],
			512, 512);
	}
	if (data->player->no_mana_fall == 1)
		data->player->no_mana_fall_dmg++;
}
