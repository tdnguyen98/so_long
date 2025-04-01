/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_projectiles_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:01:48 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:10:23 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_foe_projectiles(t_data *data, t_foe *foe)
{
	if (foe->projectile1 != NULL)
	{
		foe_projectiles(data, foe->projectile1);
		if (foe->projectile1->is_dead == 1)
			foe->projectile1 = kill_foe_projectile(foe->projectile1);
	}
	if (foe->projectile2 != NULL)
	{
		foe_projectiles(data, foe->projectile2);
		if (foe->projectile2->is_dead == 1)
			foe->projectile2 = kill_foe_projectile(foe->projectile2);
	}
	if (foe->projectile3 != NULL)
	{
		foe_projectiles(data, foe->projectile3);
		if (foe->projectile3->is_dead == 1)
			foe->projectile3 = kill_foe_projectile(foe->projectile3);
	}
}

t_proj	*kill_foe_projectile(t_proj *proj)
{
	free(proj);
	proj = NULL;
	return (proj);
}

void	foe_projectiles(t_data *data, t_proj *proj)
{
	move_projectile(data, proj, proj->direction);
	draw_projectile(data, proj->pos[0] - (data->player->pos[0] - 512),
		proj->pos[1] - (data->player->pos[1] - 512), proj);
	projectile_new_collision(proj);
	if (aabb_foe_proj(data, proj, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)))
	{
		proj->is_dead = 1;
		data->player->life_points -= 50;
	}
}

void	move_projectile(t_data *data, t_proj *projectile, int dir)
{
	if (dir == 0)
		move_projectile_right(data, projectile);
	if (dir == 1)
		move_projectile_left(data, projectile);
}

void	draw_projectile(t_data *data, int x, int y, t_proj *proj)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900)
		return ;
	if (proj->nbr == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[19], x, y);
	else if (proj->nbr == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[18], x, y);
	else if (proj->nbr == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[21], x, y);
	else if (proj->nbr == 5)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[20], x, y);
	else if (proj->nbr == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[23], x, y);
	else if (proj->nbr == 6)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.foe[22], x, y);
}
