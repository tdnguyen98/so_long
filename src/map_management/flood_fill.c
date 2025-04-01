/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:08:17 by thenguye          #+#    #+#             */
/*   Updated: 2024/04/26 12:47:30 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_char_player(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map->map[row] != NULL)
	{
		col = 0;
		while (map->map[row][col] != '\0')
		{
			if (map->map[row][col] == 'P')
			{
				if (row == 0 || row == (int)map->height - 1
					|| col == 0 || col == (int)map->width - 1)
					map_error(map, map->error + 2);
				flood_fill(map, row, col);
				map->player_pos[0] = col;
				map->player_pos[1] = row;
				return ;
			}
			col++;
		}
		row++;
	}
	map_error(map, map->error + 3);
}

void	flood_fill(t_map *map, int row, int col)
{
	if (map->map[row][col] == 'P')
		map->map[row][col] = 'p';
	else if (map->map[row][col] == 'C')
		map->map[row][col] = 'c';
	else if (map->map[row][col] == 'E')
		map->map[row][col] = 'e';
	else if (map->map[row][col] == '0')
		map->map[row][col] = 'X';
	if (is_next_char_ok(map->map[row - 1][col]) && row - 1 > 0)
		flood_fill(map, row - 1, col);
	if (is_next_char_ok(map->map[row + 1][col])
		&& row + 1 < (int)map->height - 1)
		flood_fill(map, row + 1, col);
	if (is_next_char_ok(map->map[row][col + 1])
		&& col + 1 < (int)map->width - 1)
		flood_fill(map, row, col + 1);
	if (is_next_char_ok(map->map[row][col - 1]) && col - 1 > 0)
		flood_fill(map, row, col - 1);
	map->is_flooded = 1;
	return ;
}

int	is_next_char_ok(char c)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'F' || c == 'P')
		return (1);
	return (0);
}
