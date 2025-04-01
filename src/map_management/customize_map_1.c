/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:06:58 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 11:50:29 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_block_a(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_a += 1;
		return (1);
	}
	return (0);
}

int	is_block_b(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[1]))
		return (1);
	return (0);
}

int	is_block_c(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_c += 1;
		return (1);
	}
	return (0);
}

int	is_block_d(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_d += 1;
		return (1);
	}
	return (0);
}
