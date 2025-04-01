/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_foe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:01:29 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 14:23:52 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	aabb_foe(t_data *data, t_foe *collision, int x, int y)
{
	if (data->player->pos_top_left[0] < collision->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > collision->pos_top_left[0] - x
		&& data->player->pos_top_left[1] < collision->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1] > collision->pos_top_right[1] - y)
		return (1);
	return (0);
}

int	aabb_foe_distance(t_data *data, t_foe *collision, int x, int y)
{
	if (collision->direction == 0)
	{
		if (data->player->pos_top_left[0]
			< collision->pos_bottom_right[0] - x + 1000
			&& data->player->pos_top_right[0] > collision->pos_top_left[0] - x
			&& data->player->pos_top_left[1]
			< collision->pos_bottom_right[1] - y
			&& data->player->pos_bottom_left[1]
			> collision->pos_top_right[1] - y)
			return (1);
	}
	else
	{
		if (data->player->pos_top_left[0] < collision->pos_bottom_right[0] - x
			&& data->player->pos_top_right[0]
			> collision->pos_top_left[0] - x - 1000
			&& data->player->pos_top_left[1]
			< collision->pos_bottom_right[1] - y
			&& data->player->pos_bottom_left[1]
			> collision->pos_top_right[1] - y)
			return (1);
	}
	return (0);
}

int	aabb_foe_proj(t_data *data, t_proj *collision, int x, int y)
{
	if (data->player->pos_top_left[0] < collision->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > collision->pos_top_left[0] - x
		&& data->player->pos_top_left[1] < collision->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1] > collision->pos_top_right[1] - y)
		return (1);
	return (0);
}

int	aabb_player_projectile(t_foe *foe, t_proj *collision)
{
	if (foe->pos_top_left[0] < collision->pos_bottom_right[0]
		&& foe->pos_top_right[0] > collision->pos_top_left[0]
		&& foe->pos_top_left[1] < collision->pos_bottom_right[1]
		&& foe->pos_bottom_left[1] > collision->pos_top_right[1])
		return (1);
	return (0);
}

int	aabb_exit(t_data *data, int x, int y)
{
	if (data->player->pos_top_left[0] < data->map.exit->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > data->map.exit->pos_top_left[0] - x
		&& data->player->pos_top_left[1]
		< data->map.exit->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1]
		> data->map.exit->pos_top_right[1] - y)
		return (1);
	return (0);
}
