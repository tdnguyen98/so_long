/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_lights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:38:20 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 23:25:26 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_light(t_data *data)
{
	t_collect	*light;

	light = data->map.collect;
	while (light != NULL)
	{
		if (light->light == 1)
		{
			move_light(light);
			if (check_collision_light(data, light))
				light->light = 0;
			draw_tile_light(data, light->light_pos[0]
				- (data->player->pos[0] - 512),
				light->light_pos[1] - (data->player->pos[1] - 512), light);
		}
		light = light->next;
	}
}

void	draw_tile_light(t_data *data, int x, int y, t_collect *light)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900
		|| light->light == 0)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.collectible[5], x, y);
}

void	move_light(t_collect *light)
{
	light->light_offset = (light->light_offset + 1) % 80;
	if (light->light_offset < 40)
		light->light_pos[1] += 1;
	else
		light->light_pos[1] -= 1;
	new_collision_light(light);
}

void	new_collision_light(t_collect *light)
{
	light->pos_top_left[0] = light->light_pos[0] + 100;
	light->pos_top_left[1] = light->light_pos[1] + 85;
	light->pos_top_right[0] = light->light_pos[0] + 148;
	light->pos_top_right[1] = light->light_pos[1] + 85;
	light->pos_bottom_left[0] = light->light_pos[0] + 100;
	light->pos_bottom_left[1] = light->light_pos[1] + 178;
	light->pos_bottom_right[0] = light->light_pos[0] + 148;
	light->pos_bottom_right[1] = light->light_pos[1] + 178;
}

int	check_collision_light(t_data *data, t_collect *light)
{
	if (aabb_light(data, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512), light))
	{
		data->map.collectible--;
		return (1);
	}
	return (0);
}
