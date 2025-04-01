/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:36:47 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 23:46:26 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	aabb_staff(t_data *data, int x, int y)
{
	if (data->player->pos_top_left[0] < data->map.staff->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > data->map.staff->pos_top_left[0] - x
		&& data->player->pos_top_left[1]
		< data->map.staff->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1]
		> data->map.staff->pos_top_right[1] - y)
		return (1);
	return (0);
}

int	aabb_scroll_orb(t_data *data, int x, int y)
{
	if (data->player->pos_top_left[0]
		< data->map.scroll->o_pos_bottom_right[0] - x
		&& data->player->pos_top_right[0]
		> data->map.scroll->o_pos_top_left[0] - x
		&& data->player->pos_top_left[1]
		< data->map.scroll->o_pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1]
		> data->map.scroll->o_pos_top_right[1] - y)
		return (1);
	return (0);
}

int	aabb_scroll_heal(t_data *data, int x, int y)
{
	if (data->player->pos_top_left[0]
		< data->map.scroll->h_pos_bottom_right[0] - x
		&& data->player->pos_top_right[0]
		> data->map.scroll->h_pos_top_left[0] - x
		&& data->player->pos_top_left[1]
		< data->map.scroll->h_pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1]
		> data->map.scroll->h_pos_top_right[1] - y)
		return (1);
	return (0);
}

int	aabb_light(t_data *data, int x, int y, t_collect *light)
{
	if (data->player->pos_top_left[0] < light->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > light->pos_top_left[0] - x
		&& data->player->pos_top_left[1]
		< light->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1]
		> light->pos_top_right[1] - y)
		return (1);
	return (0);
}
