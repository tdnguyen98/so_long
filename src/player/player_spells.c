/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_spells.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:54:43 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:37:35 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_spells(t_data *data)
{
	if (data->player->spells[0] == 1
		&& data->player->got_items[0] == 1
		&& data->player->got_items[1] == 1
		&& data->player->cast_spell_anim[0] == 0
		&& data->player->projectile1 == NULL)
		spell_1_orb(data);
	if (data->player->spells[1] == 1
		&& data->player->got_items[0] == 1
		&& data->player->got_items[2] == 1
		&& data->player->cast_spell_anim[0] == 0)
		spell_2_heal(data);
}

void	spell_1_orb(t_data *data)
{
	if (data->player->spells[0] == 1)
	{
		if (data->player->mana_points >= 300 && data->player->is_on_ground == 1)
		{
			data->player->mana_points -= 300;
			data->player->cast_spell_anim[0] = 1;
			create_orb(data);
		}
	}
}

void	create_orb(t_data *data)
{
	if (data->player->direction == 0)
	{
		data->player->projectile1 = new_projectile(data->player->pos[0],
				data->player->pos[1], 1);
	}
	else if (data->player->direction == 1)
	{
		data->player->projectile1 = new_projectile(data->player->pos[0],
				data->player->pos[1], 6);
	}
}

void	spell_2_heal(t_data *data)
{
	if (data->player->spell_heal_timer[1] == 0)
	{
		if (data->player->mana_points >= 500 && data->player->is_on_ground == 1)
		{
			data->player->mana_points -= 500;
			data->player->spell_heal_timer[0] = 1;
			data->player->spell_heal_timer[1] = 1;
			data->player->cast_spell_anim[0] = 1;
		}
	}
}

void	health_regen(t_data *data)
{
	if ((data->player->spell_heal_timer[0] == 1)
		&& (data->player->spell_heal_timer[2] % 6 == 0)
		&& (data->player->life_points < 300))
		data->player->life_points += 1;
}
