/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:23:52 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 11:39:01 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_block_j(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_j += 1;
		return (1);
	}
	return (0);
}

int	is_block_k(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[1])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_k += 1;
		return (1);
	}
	return (0);
}

int	is_block_l(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[1])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_l += 1;
		return (1);
	}
	return (0);
}

int	is_block_m(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[0])
		&& check_char(map->map[y + 1][x], str[1]))
	{
		map->block_m += 1;
		return (1);
	}
	return (0);
}

int	is_block_n(t_map *map, int y, int x, char **str)
{
	if (check_char(map->map[y - 1][x], str[0])
		&& check_char(map->map[y][x - 1], str[0])
		&& check_char(map->map[y][x + 1], str[1])
		&& check_char(map->map[y + 1][x], str[0]))
	{
		map->block_n += 1;
		return (1);
	}
	return (0);
}
