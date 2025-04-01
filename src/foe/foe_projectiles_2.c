/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_projectiles_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:11:03 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:10:30 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	projectile_new_collision(t_proj *projectile)
{
	if (projectile->nbr == 1)
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 210, projectile->pos[1] + 140);
	else if (projectile->nbr == 2)
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 57, projectile->pos[1] + 61);
	else if (projectile->nbr == 3)
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 28, projectile->pos[1] + 213);
	else if (projectile->nbr == 4)
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 174, projectile->pos[1] + 61);
	else if (projectile->nbr == 5)
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 205, projectile->pos[1] + 213);
	else
		projectile_new_collision_offset(projectile,
			projectile->pos[0] + 28, projectile->pos[1] + 140);
}

void	projectile_new_collision_offset(t_proj *proj, int x, int y)
{
	proj->pos_top_left[0] = x;
	proj->pos_top_left[1] = y;
	proj->pos_top_right[0] = x + 25;
	proj->pos_top_right[1] = y;
	proj->pos_bottom_left[0] = x;
	proj->pos_bottom_left[1] = y + 25;
	proj->pos_bottom_right[0] = x + 25;
	proj->pos_bottom_right[1] = y + 25;
}

void	move_projectile_right(t_data *data, t_proj *proj)
{
	int	x;
	int	speed;

	speed = 10;
	while (speed > 0)
	{
		x = ((proj->pos_bottom_right[0] + speed) / 256);
		if (check_map_foe_projectiles(data->map.map[(proj->pos_bottom_right[1]
						/ 256)][x])
			|| check_map_foe_projectiles(data->map.map[(proj->pos_top_right[1]
						/ 256)][x]))
		{
			proj->pos[0] += speed;
			return ;
		}
		speed--;
	}
	if (speed == 0)
		proj->is_dead = 1;
}

void	move_projectile_left(t_data *data, t_proj *proj)
{
	int	x;
	int	speed;

	speed = 10;
	while (speed > 0)
	{
		x = ((proj->pos_bottom_left[0] - speed) / 256);
		if (check_map_foe_projectiles(data->map.map[(proj->pos_bottom_left[1]
						/ 256)][x])
			|| check_map_foe_projectiles(data->map.map[(proj->pos_top_left[1]
						/ 256)][x]))
		{
			proj->pos[0] -= speed;
			return ;
		}
		speed--;
	}
	if (speed == 0)
		proj->is_dead = 1;
}
