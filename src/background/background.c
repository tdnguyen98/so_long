/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:33:32 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 22:51:24 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_data *data)
{
	int			x_player;
	int			y_player;
	int			x;
	int			y;

	x_player = data->player->pos[0];
	y_player = data->player->pos[1];
	x = 0;
	y = 0;
	while (y < (int)data->map.height)
	{
		x = 0;
		while (x < (int)data->map.width)
		{
			draw_tile_backround(data, (x * 256) - (x_player - 512),
				(y * 256) - (y_player - 512), data->map.map[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_tile_backround(t_data *data, int x, int y, char c)
{
	if (x < -256 || x > 1600 || y < -256 || y > 900)
	{
		set_collision(data, x, y, 0);
		return ;
	}
	else if (c != 'B' && ((c >= '1' && c <= '4') || (c >= 'A' && c <= 'P')))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.background[get_background_index(c)], x, y);
		set_collision(data, x, y, 0);
	}
	else if (c >= 'Q' && c <= 'S')
		set_tile_trap_collision(data, x, y, c);
}

int	get_background_index(char c)
{
	if (c == '1')
		return (0);
	else if (c == '2')
		return (3);
	else if (c == '3')
		return (2);
	else if (c == '4')
		return (1);
	else if (c == 'A')
		return (4);
	else if (c == 'C')
		return (5);
	else if (c == 'D')
		return (6);
	else if (c == 'E')
		return (7);
	else if (c == 'F')
		return (8);
	else if (c == 'G')
		return (9);
	else if (c == 'H')
		return (10);
	else if (c == 'I')
		return (11);
	return (get_background_index_2(c));
}

int	get_background_index_2(char c)
{
	if (c == 'J')
		return (12);
	else if (c == 'K')
		return (13);
	else if (c == 'L')
		return (14);
	else if (c == 'M')
		return (15);
	else if (c == 'N')
		return (16);
	else if (c == 'O')
		return (17);
	else if (c == 'P')
		return (18);
	else if (c == 'Q')
		return (19);
	else if (c == 'R')
		return (22);
	else if (c == 'S')
		return (25);
	return (0);
}
