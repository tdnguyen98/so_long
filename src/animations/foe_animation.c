/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:13:11 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/06 16:39:41 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_foe(t_data *data, int x, int y, t_foe *foe)
{
	if (foe->anim_delay >= 74)
		foe->anim_delay = 0;
	if (x < -256 || x > 1600 || y < -256 || y > 900)
		return ;
	if (foe->is_dead)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[24], x, y);
		return ;
	}
	if (foe->is_attacking)
	{
		if (foe->is_attacking == 1)
			foe_attack_01(data, x, y, foe);
		else
			foe_attack_02(data, x, y, foe);
	}
	else
	{
		if (foe->direction == 0)
			foe_walk_right(data, x, y, foe);
		else
			foe_walk_left(data, x, y, foe);
	}
}

void	foe_walk_right(t_data *data, int x, int y, t_foe *foe)
{
	foe->anim_delay++;
	if (foe->anim_delay <= 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[0], x, y);
	else if (foe->anim_delay <= 50)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[1], x, y);
	else if (foe->anim_delay <= 75)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[2], x, y);
		foe->anim_delay = 0;
	}
}

void	foe_walk_left(t_data *data, int x, int y, t_foe *foe)
{
	foe->anim_delay++;
	if (foe->anim_delay <= 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[3], x, y);
	else if (foe->anim_delay <= 50)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[4], x, y);
	else if (foe->anim_delay <= 75)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[5], x, y);
		foe->anim_delay = 0;
	}
}
