/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:04:11 by thenguye          #+#    #+#             */
/*   Updated: 2024/04/26 13:02:05 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	get_map(t_map *map, char *argv[])
{
	init_map_struct(map);
	check_map_extension(map, argv);
	get_height(map, argv);
	fill_map(map, argv);
	check_map_proportions(map);
	map_parsing(map, map->height);
	if (map->collectible > 0)
		define_collectibles(map);
	change_wall_in_map(map);
	add_randomness(map);
	change_map_borders(map);
	add_enemies(map);
	are_exit_scroll_staff_on_ground(map);
	return (*map);
}

void	fill_map(t_map *map, char *argv[])
{
	int		fd;
	int		line_size;
	int		i;

	line_size = 1;
	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		map_error(map, map->error);
	while (line_size)
	{
		map->map[i] = get_next_line(fd);
		if (map->map[i] == NULL)
			break ;
		line_size = ft_strlen(map->map[i]);
		if (map->map[i][line_size - 1] == '\n')
			map->map[i][line_size - 1] = '\0';
		i++;
	}
	close(fd);
}

void	check_map_proportions(t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map->map[0]);
	if (map->width == map->height)
		map_error(map, map->error + 1);
	while (i < (int)map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			map_error(map, map->error + 1);
		i++;
	}
}

void	check_map_extension(t_map *map, char *argv[])
{
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		map_error(map, map->error + 8);
}
