/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_projectile_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:42:32 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:14:04 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	proj_player_new_collision_offset(t_proj *proj, int x, int y)
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

void	move_projectile_player_right(t_data *data, t_proj *proj)
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

void	move_projectile_player_left(t_data *data, t_proj *proj)
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

void	projectile_player_hit_foe(t_data *data, t_proj *proj)
{
	t_foe	*foe;

	foe = data->map.foe;
	while (foe != NULL)
	{
		if (aabb_player_projectile(foe, proj))
		{
			foe->is_dead = 1;
			proj->is_dead = 1;
		}
		foe = foe->next;
	}
}
