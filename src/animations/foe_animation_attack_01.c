/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_animation_attack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:46:04 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/06 14:07:36 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	foe_attack_01(t_data *data, int x, int y, t_foe *foe)
{
	foe->attack_delay++;
	if (foe->direction == 0)
		foe_attack_01_right(data, x, y, foe);
	else
		foe_attack_01_left(data, x, y, foe);
	if (foe->attack_delay > 120)
	{
		foe->attack_delay = 0;
		foe->is_attacking = 0;
	}
}

void	foe_attack_01_right(t_data *data, int x, int y, t_foe *foe)
{
	if (foe->attack_delay <= 10)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[6], x, y);
	else if (foe->attack_delay <= 20)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[8], x, y);
	else if (foe->attack_delay <= 30)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[9], x, y);
	else if (foe->attack_delay <= 120)
	{
		if (foe->attack_delay % 9 <= 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[10], x, y);
		else if (foe->attack_delay % 9 <= 5)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[11], x, y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[12], x, y);
	}
}

void	foe_attack_01_left(t_data *data, int x, int y, t_foe *foe)
{
	if (foe->attack_delay <= 10)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[7], x, y);
	else if (foe->attack_delay <= 20)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[13], x, y);
	else if (foe->attack_delay <= 30)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[14], x, y);
	else if (foe->attack_delay <= 120)
	{
		if (foe->attack_delay % 9 <= 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[15], x, y);
		else if (foe->attack_delay % 9 <= 5)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[16], x, y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.foe[17], x, y);
	}
}
