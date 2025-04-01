/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:51:46 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:55:09 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->life_points = 300;
	data->player->mana_points = 900;
	data->player->pos[0] = 0;
	data->player->pos[1] = 0;
	init_player_collision(data);
	data->player->move[0] = 0;
	data->player->move[1] = 0;
	data->player->move[2] = 0;
	data->player->move[3] = 0;
	data->player->spells[0] = 0;
	data->player->spells[1] = 0;
	data->player->spell_heal_timer[0] = 0;
	data->player->spell_heal_timer[1] = 0;
	data->player->spell_heal_timer[2] = 0;
	data->player->projectile1 = NULL;
	data->player->anim_delay_fall[0] = 0;
	data->player->anim_delay_fall[1] = 0;
	data->player->is_on_ground = 0;
	data->player->no_mana_fall = 0;
	data->player->no_mana_fall_dmg = 0;
	data->player->levitating_move = 0;
	data->player->direction = 0;
	init_player_inventory(data);
	init_player_2(data);
}

void	init_player_2(t_data *data)
{
	data->player->cast_spell_anim[0] = 0;
	data->player->cast_spell_anim[1] = 0;
}

void	init_player_collision(t_data *data)
{
	data->player->pos_top_left[0] = 609;
	data->player->pos_top_left[1] = 665;
	data->player->pos_top_right[0] = 671;
	data->player->pos_top_right[1] = 665;
	data->player->pos_bottom_left[0] = 609;
	data->player->pos_bottom_left[1] = 767;
	data->player->pos_bottom_right[0] = 671;
	data->player->pos_bottom_right[1] = 767;
}

void	get_player_pos(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map.map[y] != NULL)
	{
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == 'p')
			{
				data->player->pos[0] = ((x + 1) * 256);
				data->player->pos[1] = ((y + 1) * 256);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	draw_player(t_data *data)
{
	animation(data);
	draw_player_projectile(data);
	return (1);
}
