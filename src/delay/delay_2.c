/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:55:36 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:45:55 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delay_trap(t_data *data)
{
	t_trap	*trap;

	trap = data->map.trap;
	while (trap != NULL)
	{
		if (trap->is_triggered == 1)
		{
			trap->delay++;
			if (trap->delay >= 200)
			{
				trap->is_triggered = 0;
				trap->delay = 0;
			}
		}
		trap = trap->next;
	}
}

void	delay_cast_spell_anim(t_data *data)
{
	if (data->player->cast_spell_anim[0] == 1)
	{
		data->player->cast_spell_anim[1]++;
		if (data->player->cast_spell_anim[1] >= 30)
		{
			data->player->cast_spell_anim[0] = 0;
			data->player->cast_spell_anim[1] = 0;
		}
	}
}
