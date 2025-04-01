/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_staff_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:57:12 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:49:12 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision_staff(t_data *data)
{
	if (aabb_staff(data, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)))
	{
		data->map.collectible--;
		data->player->got_items[0] = 1;
		data->player->anim_staff_offset = 22;
		return (1);
	}
	return (0);
}
