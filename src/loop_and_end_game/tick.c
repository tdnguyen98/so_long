/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:08:15 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/20 13:29:02 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tick(t_data *data)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = now - data->lm;
	if (diff_millisecs > 16)
	{
		delay(data);
		check_player_stats_and_inventory(data);
		fps(data);
		if (data->collision != NULL)
		{
			free_collision(data->collision);
			data->collision = NULL;
		}
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
		movement(data);
		show_fps(data);
	}
	return (1);
}

void	draw(t_data *data)
{
	if (data->ending[0] == 0)
	{
		draw_background(data);
		draw_exit(data);
		draw_player(data);
		draw_foe(data);
		draw_collectibles(data);
		draw_hud(data);
		trap(data);
	}
	else
	{
		display_ending(data);
		close_game(data);
	}
}
