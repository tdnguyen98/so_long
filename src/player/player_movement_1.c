/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:54:25 by thenguye          #+#    #+#             */
/*   Updated: 2025/04/01 20:08:21 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_move(t_data *data, int keysym)
{
	if (keysym == S_KEY)
		data->player->move[3] = 1;
	else if (keysym == D_KEY)
		data->player->move[1] = 1;
	else if (keysym == A_KEY)
		data->player->move[0] = 1;
	else if (keysym == W_KEY)
		data->player->move[2] = 1;
	else if (keysym == SKILL_1 || keysym == SKILL_1_NUMPAD)
		data->player->spells[0] = 1;
	else if (keysym == SKILL_2 || keysym == SKILL_2_NUMPAD)
		data->player->spells[1] = 1;
}

void	reset_move(t_data *data, int keysym)
{
	if (keysym == S_KEY)
		data->player->move[3] = 0;
	else if (keysym == D_KEY)
	{
		data->player->move[1] = 0;
		data->player->is_running = 0;
	}
	else if (keysym == A_KEY)
	{
		data->player->move[0] = 0;
		data->player->is_running = 0;
	}
	else if (keysym == W_KEY)
	{
		data->player->move[2] = 0;
		data->player->is_flying = 0;
	}
	else if (keysym == SKILL_1 || keysym == SKILL_1_NUMPAD)
		data->player->spells[0] = 0;
	else if (keysym == SKILL_2 || keysym == SKILL_2_NUMPAD)
		data->player->spells[1] = 0;
}

void	movement(t_data *data)
{
	if (movement_1(data))
		return ;
	movement_2(data);
	movement_3(data);
	movement_4(data);
}

int	movement_1(t_data *data)
{
	int	i;

	i = 0;
	if (data->player->no_mana_fall == 1)
	{
		i += check_collision(data, 4);
		data->player->pos[1] += i;
		if (i == 0)
		{
			data->player->is_on_ground = 1;
			data->player->is_falling = 0;
			data->player->no_mana_fall = 0;
			data->player->life_points -= data->player->no_mana_fall_dmg;
		}
		else
			data->player->is_on_ground = 0;
		return (1);
	}
	else
		return (0);
}

void	movement_2(t_data *data)
{
	if (data->player->move[0] && data->player->move[3] == 0)
	{
		if (data->player->is_on_ground == 1
			|| !(data->player->is_on_ground == 0
				&& data->player->mana_points <= 0))
		{
			data->player->pos[0] -= check_collision(data, 0);
			data->player->is_running = 1;
		}
	}
	if (data->player->move[1] && data->player->move[3] == 0)
	{
		if (data->player->is_on_ground == 1
			|| !(data->player->is_on_ground == 0
				&& data->player->mana_points <= 0))
		{
			data->player->pos[0] += check_collision(data, 1);
			data->player->is_running = 1;
		}
	}
}
