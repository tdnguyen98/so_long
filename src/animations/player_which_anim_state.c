/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_which_anim_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:37:36 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/14 14:07:22 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_player_meditating(t_data *data)
{
	if (data->player->is_on_ground == 0 && data->player->move[3] == 1)
		return (1);
	return (0);
}

int	is_player_idleling(t_data *data)
{
	if (data->player->is_on_ground && data->player->is_flying == 0
		&& (data->player->is_running == 0 || (data->player->move[0] == 1
				&& data->player->move[1] == 1)))
		return (1);
	return (0);
}

int	is_player_running(t_data *data)
{
	if (data->player->is_on_ground && data->player->is_running
		&& data->player->is_flying == 0)
		return (1);
	return (0);
}

int	is_player_flying(t_data *data)
{
	if (data->player->is_on_ground == 0 && data->player->is_running == 0
		&& data->player->move[3] == 0 && data->player->is_flying == 1
		&& data->player->mana_points > 0)
		return (1);
	else if (data->player->is_on_ground == 0 && data->player->is_running == 1
		&& data->player->move[3] == 0 && data->player->is_flying == 1
		&& data->player->mana_points > 0)
		return (1);
	else if (data->player->is_on_ground == 0 && data->player->is_running == 1
		&& data->player->move[3] == 0 && data->player->is_flying == 0
		&& data->player->mana_points > 0)
		return (1);
	return (0);
}

int	is_player_falling(t_data *data)
{
	if (data->player->is_on_ground == 0 && data->player->is_running == 0
		&& data->player->is_flying == 0)
		return (1);
	return (0);
}
