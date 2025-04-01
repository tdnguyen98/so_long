/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:19:24 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 13:05:40 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_3(t_data *data)
{
	if (data->player->move[2] && data->player->move[3] == 0)
	{
		if ((data->player->mana_points > 1 && data->player->is_on_ground == 0)
			|| (data->player->is_on_ground == 1
				&& data->player->mana_points > 50))
		{
			data->player->pos[1] -= check_collision(data, 2);
			data->player->is_on_ground = 0;
			data->player->is_flying = 1;
			data->player->is_falling = 0;
			data->player->anim_delay_fall[0] = 0;
			data->player->anim_delay_fall[1] = 0;
		}
		else
		{
			data->player->is_flying = 0;
			data->player->is_falling = 1;
			data->player->no_mana_fall = 1;
		}
	}
}

void	movement_4(t_data *data)
{
	int	i;

	i = 0;
	if (data->player->move[3] == 0)
	{
		i += check_collision(data, 4);
		data->player->pos[1] += i;
		if (i == 0)
		{
			data->player->is_on_ground = 1;
			data->player->is_falling = 0;
			data->player->no_mana_fall = 0;
		}
		else
			data->player->is_on_ground = 0;
	}
	if (data->player->move[3] == 1)
	{
		data->player->is_falling = 0;
		data->player->anim_delay_fall[0] = 1;
		data->player->anim_delay_fall[1] = 80;
	}
	direction(data->player);
}

void	direction(t_player *player)
{
	if (player->move[0] && player->move[1])
		return ;
	if (player->move[0])
		player->direction = 1;
	else if (player->move[1])
		player->direction = 0;
}
