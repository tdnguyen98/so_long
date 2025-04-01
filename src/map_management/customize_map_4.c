/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:24:56 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:54:39 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_block_o(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_o += 1;
		return (1);
	}
	return (0);
}

int	is_block_p(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_p += 1;
		return (1);
	}
	return (0);
}

void	add_randomness(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < (int)map->height - 1)
	{
		x = 1;
		while (x < (int)map->width - 1)
		{
			if (map->map[y][x] == 'C' && map->block_c > 5 && probability(80))
				map->map[y][x] = '1';
			if (map->map[y][x] == 'F' && map->block_f > 5 && probability(80))
				get_trap(map, x, y, 22);
			if (map->map[y][x] == 'D' && map->block_d > 2 && probability(80))
				get_trap(map, x, y, 19);
			if (map->map[y][x] == 'E' && map->block_e > 2 && probability(80))
				get_trap(map, x, y, 25);
			if (map->map[y][x] == 'e' && (map->map[y + 1][x] == 'C'))
				map->map[y + 1][x] = '1';
			x++;
		}
		y++;
	}
}
