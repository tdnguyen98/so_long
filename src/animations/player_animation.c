/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:48 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 11:43:06 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_data *data)
{
	if (data->player->no_mana_fall == 1)
		animation_fall(data);
	else if (data->player->cast_spell_anim[0] == 1)
		animation_cast_spell(data);
	else if (is_player_meditating(data))
		animation_meditating(data);
	else if (is_player_idleling(data))
		animation_idle(data);
	else if (is_player_running(data))
		animation_run(data);
	else if (is_player_flying(data) && data->player->is_falling == 0)
		animation_fly(data);
	else if (is_player_falling(data))
	{
		data->player->anim_delay_fall[0] = 1;
		if (data->player->is_falling == 1)
			animation_fall(data);
		else
			animation_fly(data);
	}
	else
		animation_fly(data);
}
