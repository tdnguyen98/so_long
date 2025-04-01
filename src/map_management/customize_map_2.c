/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:23:41 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 11:39:19 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_block_e(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_e += 1;
		return (1);
	}
	return (0);
}

int	is_block_f(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_f += 1;
		return (1);
	}
	return (0);
}

int	is_block_g(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_g += 1;
		return (1);
	}
	return (0);
}

int	is_block_h(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_h += 1;
		return (1);
	}
	return (0);
}

int	is_block_i(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_i += 1;
		return (1);
	}
	return (0);
}
