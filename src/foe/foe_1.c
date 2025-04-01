/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:39:41 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:35:00 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_foe(t_data *data)
{
	t_foe	*foe;

	foe = data->map.foe;
	while (foe != NULL)
	{
		animation_foe(data, foe->pos[0] - (data->player->pos[0] - 512),
			foe->pos[1] - (data->player->pos[1] - 512), foe);
		if (foe->is_dead == 0)
		{
			if (foe->is_attacking == 0)
				move_foe(data, foe);
			new_collision_foe(foe);
			foe = is_foe_attacking_01(foe, data);
			foe = is_foe_attacking_02(foe, data);
			get_foe_projectiles(data, foe);
			if (foe->cooldown >= 1)
				delay_foe_attack_02(foe);
		}
		else
		{
			get_foe_projectiles(data, foe);
			dead_collision_foe(foe);
		}
		foe = foe->next;
	}
}

void	move_foe(t_data *data, t_foe *foe)
{
	if (foe->direction == 0)
		move_foe_right(data, foe);
	else
		move_foe_left(data, foe);
}

void	move_foe_right(t_data *data, t_foe *foe)
{
	int	x;
	int	speed;

	speed = 3;
	while (speed > 0)
	{
		x = ((foe->pos_bottom_right[0] + speed) / 256);
		if ((data->map.map[(foe->pos_bottom_right[1] / 256) + 1][x] != 'X')
			&& ((data->map.map[(foe->pos_bottom_right[1] / 256)][x] == 'X')
			|| (data->map.map[(foe->pos_bottom_right[1] / 256)][x] == 'Z')))
		{
			foe->pos[0] += speed;
			return ;
		}
		speed--;
	}
	if (speed == 0)
		foe->direction = 1;
}

void	move_foe_left(t_data *data, t_foe *foe)
{
	int	x;
	int	speed;

	speed = 3;
	while (speed > 0)
	{
		x = ((foe->pos_bottom_left[0] - speed) / 256);
		if ((data->map.map[(foe->pos_bottom_left[1] / 256) + 1][x] != 'X')
			&& ((data->map.map[(foe->pos_bottom_left[1] / 256)][x] == 'X')
			|| (data->map.map[(foe->pos_bottom_left[1] / 256)][x] == 'Z')))
		{
			foe->pos[0] -= speed;
			return ;
		}
		speed--;
	}
	if (speed == 0)
		foe->direction = 0;
}

void	new_collision_foe(t_foe *foe)
{
	foe->pos_top_left[0] = foe->pos[0] + 100;
	foe->pos_top_left[1] = foe->pos[1] + 163;
	foe->pos_top_right[0] = foe->pos[0] + 136;
	foe->pos_top_right[1] = foe->pos[1] + 163;
	foe->pos_bottom_left[0] = foe->pos[0] + 100;
	foe->pos_bottom_left[1] = foe->pos[1] + 255;
	foe->pos_bottom_right[0] = foe->pos[0] + 136;
	foe->pos_bottom_right[1] = foe->pos[1] + 255;
}
