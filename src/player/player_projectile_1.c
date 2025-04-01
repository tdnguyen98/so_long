/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_projectile_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:46:41 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:14:52 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_projectile(t_data *data)
{
	if (data->player->projectile1 != NULL)
	{
		if (data->player->projectile1->direction == 0)
			data->player->projectile1->nbr = 1;
		else
			data->player->projectile1->nbr = 6;
		player_projectiles(data, data->player->projectile1);
		if (data->player->projectile1->is_dead == 1)
		{
			free(data->player->projectile1);
			data->player->projectile1 = NULL;
		}
	}
}

void	player_projectiles(t_data *data, t_proj *proj)
{
	move_proj_player(data, proj, proj->direction);
	draw_proj_player(data, proj->pos[0] - (data->player->pos[0] - 512),
		proj->pos[1] - (data->player->pos[1] - 512), proj);
	projectile_player_new_collision(proj);
	projectile_player_hit_foe(data, proj);
}

void	move_proj_player(t_data *data, t_proj *projectile, int dir)
{
	if (dir == 0)
		move_projectile_right(data, projectile);
	if (dir == 1)
		move_projectile_left(data, projectile);
}

void	draw_proj_player(t_data *data, int x, int y, t_proj *proj)
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

void	projectile_player_new_collision(t_proj *projectile)
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
