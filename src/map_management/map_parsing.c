/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:19:02 by thenguye          #+#    #+#             */
/*   Updated: 2024/04/26 13:01:34 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(t_map *map, size_t height)
{
	int	i;

	i = 0;
	if (height == 0)
		return ;
	if (map->is_flooded == 0)
		find_char_player(map);
	while (map->map[map->height - height][i] != '\0')
	{
		if (map->map[map->height - height][0] != '1'
			|| map->map[map->height - height][map->width - 1] != '1')
			map_error(map, map->error + 2);
		if (map->map[map->height - 1][i] != '1' || map->map[0][i] != '1')
			map_error(map, map->error + 2);
		is_char_valid(map, map->map[map->height - height][i]);
		if (map->map[map->height - height][i] == 'p'
			|| map->map[map->height - height][i] == 'c'
			|| map->map[map->height - height][i] == 'e')
			get_map_utils(map, map->height - height, i);
		i++;
	}
	map_parsing(map, height - 1);
	check_map_mandatory(map);
}

void	get_map_utils(t_map *map, int row, int col)
{
	if (map->map[row][col] == 'p')
		map->player++;
	else if (map->map[row][col] == 'c')
	{
		map->collectible++;
		ft_lstadd_back(&map->collect_pos, ft_lstnew(row));
		ft_lstadd_back(&map->collect_pos, ft_lstnew(col));
	}
	else if (map->map[row][col] == 'e')
	{
		map->exit_count++;
		map->exit->pos[0] = col * 256;
		map->exit->pos[1] = row * 256;
		map->exit->pos_top_left[0] = map->exit->pos[0] + 38;
		map->exit->pos_top_left[1] = map->exit->pos[1] + 64;
		map->exit->pos_top_right[0] = map->exit->pos[0] + 220;
		map->exit->pos_top_right[1] = map->exit->pos[1] + 64;
		map->exit->pos_bottom_left[0] = map->exit->pos[0] + 38;
		map->exit->pos_bottom_left[1] = map->exit->pos[1] + 256;
		map->exit->pos_bottom_right[0] = map->exit->pos[0] + 220;
		map->exit->pos_bottom_right[1] = map->exit->pos[1] + 256;
	}
	else if (map->map[row][col] == 'f')
		map->foe++;
}

void	check_map_mandatory(t_map *map)
{
	if (map->player != 1)
		map_error(map, map->error + 3);
	else if (map->collectible <= 0)
		map_error(map, map->error + 4);
	else if (map->exit_count != 1)
		map_error(map, map->error + 5);
}

void	is_char_valid(t_map *map, char c)
{
	if (c == 'P' || c == 'C' || c == 'E')
		map_error(map, map->error + 7);
	if (c != '0' && c != 'X' && c != '1' && c != 'c' && c != 'e' && c != 'p')
		map_error(map, map->error + 6);
}

