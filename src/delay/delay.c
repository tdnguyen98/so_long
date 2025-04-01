/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:15:53 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:38:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delay(t_data *data)
{
	delay_damage_taken(data);
	delay_anim_fall(data);
	delay_cooldown_heal(data);
	delay_cast_spell_anim(data);
	delay_trap(data);
}

void	delay_damage_taken(t_data *data)
{
	if (data->player->damage_taken_delay[0] == 1)
	{
		data->player->damage_taken_delay[1]++;
	}
	if (data->player->damage_taken_delay[1] >= 170)
	{
		data->player->damage_taken_delay[1] = 0;
		data->player->damage_taken_delay[0] = 0;
	}
}

void	delay_anim_fall(t_data *data)
{
	if ((data->player->is_on_ground == 0
			&& data->player->anim_delay_fall[0] == 1
			&&data->player->move[3] == 0)
		|| data->player->is_falling == 1)
	{
		data->player->anim_delay_fall[1]++;
		if (data->player->anim_delay_fall[1] <= 80)
			data->player->anim_delay_fall[1]++;
		if (data->player->anim_delay_fall[1] > 80)
		{
			data->player->is_falling = 1;
		}
	}
	else
	{
		data->player->anim_delay_fall[0] = 0;
		data->player->anim_delay_fall[1] = 0;
		data->player->is_falling = 0;
	}
}

void	delay_foe_attack_02(t_foe *foe)
{
	if (foe->cooldown >= 1)
		foe->cooldown++;
	if (foe->cooldown >= 150)
		foe->cooldown = 0;
}

void	delay_cooldown_heal(t_data *data)
{
	if (data->player->spell_heal_timer[0] == 1
		|| data->player->spell_heal_timer[1] == 1)
		data->player->spell_heal_timer[2]++;
	if (data->player->spell_heal_timer[2] >= 900)
		data->player->spell_heal_timer[0] = 0;
	if (data->player->spell_heal_timer[2] >= 2000)
	{
		data->player->spell_heal_timer[1] = 0;
		data->player->spell_heal_timer[2] = 0;
	}
}
