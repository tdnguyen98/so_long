/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mana.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:20:26 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/14 14:16:16 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mana_management(t_data *data)
{
	if (data->player->no_mana_fall == 0)
		mana_regen(data);
	mana_cost_fly(data);
	player_spells(data);
}

void	mana_regen(t_data *data)
{
	if (data->player->mana_points < 900)
	{
		if (data->player->is_on_ground == 0 && data->player->move[3] == 1)
			data->player->mana_points += 1;
		data->player->mana_points += 1;
	}
}

void	mana_cost_fly(t_data *data)
{
	if (data->player->mana_points > 0)
	{
		if (data->player->is_on_ground == 0 && data->player->is_running == 0
			&& data->player->move[3] == 0 && data->player->is_flying == 1)
			data->player->mana_points -= 2;
		else if (data->player->is_on_ground == 0
			&& data->player->is_running == 1
			&& data->player->move[3] == 0 && data->player->is_flying == 1)
			data->player->mana_points -= 2;
		else if (data->player->is_on_ground == 0
			&& data->player->is_running == 1
			&& data->player->move[3] == 0 && data->player->is_flying == 0)
			data->player->mana_points -= 2;
	}
}
