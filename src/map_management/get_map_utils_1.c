/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:08 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 22:04:04 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_struct(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player = 0;
	map->collectible = 0;
	map->collect_pos = NULL;
	map->exit = malloc(sizeof(t_exit));
	map->exit->pos[0] = 0;
	map->exit->pos[1] = 0;
	map->exit->is_open = 0;
	map->exit->is_far = 1;
	map->exit_count = 0;
	map->foe = 0;
	map->error = 0;
	map->is_flooded = 0;
	map->foe = NULL;
	map->trap = NULL;
	map->collect = NULL;
	map->staff = NULL;
	map->scroll = NULL;
	init_map_bloc(map);
}

void	init_map_bloc(t_map *map)
{
	map->block_a = 0;
	map->block_c = 0;
	map->block_d = 0;
	map->block_e = 0;
	map->block_f = 0;
	map->block_g = 0;
	map->block_h = 0;
	map->block_i = 0;
	map->block_j = 0;
	map->block_k = 0;
	map->block_l = 0;
	map->block_m = 0;
	map->block_n = 0;
	map->block_o = 0;
	map->block_p = 0;
}

void	get_height(t_map *map, char *argv[])
{
	int		fd;
	char	*line;
	int		line_size;

	line = NULL;
	line_size = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		map_error(map, map->error);
	while (line_size)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_size = ft_strlen(line);
		free(line);
		map->height++;
	}
	if (map->height == 0)
		map_error(map, map->error + 9);
	close(fd);
}

void	change_map_borders(t_map *map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < (int)map->height)
	{
		col = 0;
		while (map->map[row][col] != '\0')
		{
			if (map->map[row][0] == '1')
				map->map[row][0] = '2';
			if (map->map[row][map->width - 1] == '1')
				map->map[row][map->width - 1] = '3';
			if (map->map[0][col] == '1')
				map->map[0][col] = '4';
			col++;
		}
		row++;
	}
	map->map[0][0] = '5';
	map->map[0][map->width - 1] = '6';
	map->map[map->height - 1][0] = '7';
	map->map[map->height - 1][map->width - 1] = '8';
}

void	change_wall_in_map(t_map *map)
{
	int	col;
	int	row;

	col = 1;
	row = 1;
	while (row < (int)map->height - 1)
	{
		col = 1;
		while (col < (int)map->width - 1)
		{
			if (map->map[row][col] == '1')
				map->map[row][col] = create_interior_map(map, row, col);
			col++;
		}
		row++;
	}
}
