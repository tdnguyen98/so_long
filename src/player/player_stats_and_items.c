/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stats_and_items.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:36:21 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:37:58 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_stats_and_inventory(t_data *data)
{
	mana_management(data);
	health_regen(data);
	if (data->player->life_points <= 0)
	{
		if (data->ending[0] == 0)
			data->ending[0] = 1;
		data->ending[1] = 1;
	}
}

void	init_player_inventory(t_data *data)
{
	data->player->got_items[0] = 0;
	data->player->got_items[1] = 0;
	data->player->got_items[2] = 0;
	data->player->anim_staff_offset = 0;
}
