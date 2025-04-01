/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_animation_attack_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:23:03 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:11:55 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	foe_attack_02(t_data *data, int x, int y, t_foe *foe)
{
	foe->attack_delay++;
	if (foe->direction == 0)
		foe_attack_02_right(data, x, y, foe);
	else
		foe_attack_02_left(data, x, y, foe);
	if (foe->attack_delay > 25)
	{
		foe->attack_delay = 0;
		foe->is_attacking = 0;
	}
}

void	foe_attack_02_right(t_data *data, int x, int y, t_foe *foe)
{
	if (foe->attack_delay <= 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[6], x, y);
	if (foe->attack_delay == 10)
	{
		if (foe->projectile1 == NULL)
			foe->projectile1 = new_projectile(foe->pos[0], foe->pos[1], 1);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[19], x, y);
	}
	if (foe->attack_delay == 20)
	{
		if (foe->projectile2 == NULL)
			foe->projectile2 = new_projectile(foe->pos[0], foe->pos[1], 2);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[21], x, y);
	}
	if (foe->attack_delay == 25)
	{
		if (foe->projectile3 == NULL)
			foe->projectile3 = new_projectile(foe->pos[0], foe->pos[1], 3);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[23], x, y);
	}
}

void	foe_attack_02_left(t_data *data, int x, int y, t_foe *foe)
{
	if (foe->attack_delay <= 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[7], x, y);
	if (foe->attack_delay == 10)
	{
		if (foe->projectile1 == NULL)
			foe->projectile1 = new_projectile(foe->pos[0], foe->pos[1], 4);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[18], x, y);
	}
	if (foe->attack_delay == 20)
	{
		if (foe->projectile2 == NULL)
			foe->projectile2 = new_projectile(foe->pos[0], foe->pos[1], 5);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[20], x, y);
	}
	if (foe->attack_delay == 25)
	{
		if (foe->projectile3 == NULL)
			foe->projectile3 = new_projectile(foe->pos[0], foe->pos[1], 6);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[22], x, y);
	}
}

t_proj	*new_projectile(int x, int y, int direction)
{
	t_proj	*projectile;

	projectile = malloc(sizeof(t_proj));
	if (projectile == NULL)
		return (NULL);
	projectile->pos[0] = x;
	projectile->pos[1] = y;
	projectile->nbr = direction;
	projectile->is_dead = 0;
	if (direction == 1)
		projectile_collision(projectile, x + 210, y + 140, 0);
	else if (direction == 2)
		projectile_collision(projectile, x + 57, y + 61, 0);
	else if (direction == 3)
		projectile_collision(projectile, x + 28, y + 213, 0);
	else if (direction == 4)
		projectile_collision(projectile, x + 174, y + 61, 1);
	else if (direction == 5)
		projectile_collision(projectile, x + 205, y + 213, 1);
	else
		projectile_collision(projectile, x + 28, y + 140, 1);
	return (projectile);
}

void	projectile_collision(t_proj *projectile, int x, int y, int dir)
{
	projectile->pos_top_left[0] = x;
	projectile->pos_top_left[1] = y;
	projectile->pos_top_right[0] = x + 25;
	projectile->pos_top_right[1] = y;
	projectile->pos_bottom_left[0] = x;
	projectile->pos_bottom_left[1] = y + 25;
	projectile->pos_bottom_right[0] = x + 25;
	projectile->pos_bottom_right[1] = y + 25;
	if (dir == 0)
		projectile->direction = 0;
	else
		projectile->direction = 1;
}
