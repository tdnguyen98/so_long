/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_trap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:00:59 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile_trap_collision(t_data *data, int x, int y, char c)
{
	if (c == 'Q')
		set_collision_trap_right(data, x - 179, y, 3);
	else if (c == 'R')
		set_collision_trap_up(data, x, y + 179, 3);
	else if (c == 'S')
		set_collision_trap_left(data, x + 179, y, 3);
}

void	set_collision_trap_right(t_data *data, int x, int y, int type)
{
	t_collision	*no_zone;

	no_zone = malloc(sizeof(t_collision));
	if (!no_zone)
		return ;
	no_zone->collision_type[0] = 0;
	no_zone->collision_type[1] = 0;
	no_zone->collision_type[2] = 0;
	no_zone->collision_type[3] = 0;
	no_zone->top_left[0] = x + 215;
	no_zone->top_left[1] = y;
	no_zone->top_right[0] = x + 256;
	no_zone->top_right[1] = y;
	no_zone->bottom_left[0] = x + 215;
	no_zone->bottom_left[1] = y + 256;
	no_zone->bottom_right[0] = x + 256;
	no_zone->bottom_right[1] = y + 256;
	no_zone->collision_type[type] = 1;
	no_zone->next = NULL;
	ft_lstadd_back_collision(&data->collision, no_zone);
}

void	set_collision_trap_up(t_data *data, int x, int y, int type)
{
	t_collision	*no_zone;

	no_zone = malloc(sizeof(t_collision));
	if (!no_zone)
		return ;
	no_zone->collision_type[0] = 0;
	no_zone->collision_type[1] = 0;
	no_zone->collision_type[2] = 0;
	no_zone->collision_type[3] = 0;
	no_zone->top_left[0] = x;
	no_zone->top_left[1] = y;
	no_zone->top_right[0] = x + 256;
	no_zone->top_right[1] = y;
	no_zone->bottom_left[0] = x;
	no_zone->bottom_left[1] = y + 41;
	no_zone->bottom_right[0] = x + 256;
	no_zone->bottom_right[1] = y + 41;
	no_zone->collision_type[type] = 1;
	no_zone->next = NULL;
	ft_lstadd_back_collision(&data->collision, no_zone);
}

void	set_collision_trap_left(t_data *data, int x, int y, int type)
{
	t_collision	*no_zone;

	no_zone = malloc(sizeof(t_collision));
	if (!no_zone)
		return ;
	no_zone->collision_type[0] = 0;
	no_zone->collision_type[1] = 0;
	no_zone->collision_type[2] = 0;
	no_zone->collision_type[3] = 0;
	no_zone->top_left[0] = x;
	no_zone->top_left[1] = y;
	no_zone->top_right[0] = x + 41;
	no_zone->top_right[1] = y;
	no_zone->bottom_left[0] = x;
	no_zone->bottom_left[1] = y + 256;
	no_zone->bottom_right[0] = x + 41;
	no_zone->bottom_right[1] = y + 256;
	no_zone->collision_type[type] = 1;
	no_zone->next = NULL;
	ft_lstadd_back_collision(&data->collision, no_zone);
}
