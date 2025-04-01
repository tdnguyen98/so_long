/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:08:02 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:42:01 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	aabb(t_data *data, t_collision *collision, char dir, int i)
{
	if (dir == 'l')
		while (i > 0 && aabb_left(data, collision, i) == 1)
			i--;
	if (dir == 'r')
		while (i > 0 && aabb_right(data, collision, i) == 1)
			i--;
	if (dir == 'u')
	{
		i += 10;
		while (i > 0 && aabb_up(data, collision, i) == 1)
			i--;
	}
	if (dir == 'd')
	{
		i -= 3;
		while (i > 0 && aabb_down(data, collision, i) == 1)
			i--;
	}
	if (dir == 'g')
	{
		i += 5;
		while (i > 0 && aabb_down(data, collision, i) == 1)
			i--;
	}
	return (i);
}

int	aabb_down(t_data *data, t_collision *collision, int i)
{
	if (data->player->pos_top_left[0] < collision->bottom_right[0]
		&& data->player->pos_top_right[0] > collision->top_left[0]
		&& data->player->pos_top_left[1] + i < collision->bottom_right[1]
		&& data->player->pos_bottom_left[1] + i > collision->top_right[1])
		return (1);
	return (0);
}

int	aabb_up(t_data *data, t_collision *collision, int i)
{
	if (data->player->pos_top_left[0] < collision->bottom_right[0]
		&& data->player->pos_top_right[0] > collision->top_left[0]
		&& data->player->pos_top_left[1] - i < collision->bottom_right[1]
		&& data->player->pos_bottom_left[1] - i > collision->top_right[1])
		return (1);
	return (0);
}

int	aabb_left(t_data *data, t_collision *collision, int i)
{
	if (data->player->pos_top_left[0] - i < collision->bottom_right[0]
		&& data->player->pos_top_right[0] - i > collision->top_left[0]
		&& data->player->pos_top_left[1] < collision->bottom_right[1]
		&& data->player->pos_bottom_left[1] > collision->top_right[1])
		return (1);
	return (0);
}

int	aabb_right(t_data *data, t_collision *collision, int i)
{
	if (data->player->pos_top_left[0] + i < collision->bottom_right[0]
		&& data->player->pos_top_right[0] + i > collision->top_left[0]
		&& data->player->pos_top_left[1] < collision->bottom_right[1]
		&& data->player->pos_bottom_left[1] > collision->top_right[1])
		return (1);
	return (0);
}
