/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:59:11 by thenguye          #+#    #+#             */
/*   Updated: 2025/04/06 20:34:18 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		ft_putstr_fd(map->map[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;

	map.map = NULL;
	data.collision = NULL;
	data.steps = 0;
	if (argc != 2)
		return (1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1536, 900, "so_long");
	if (data.win_ptr == NULL)
		return (1);
	init_sprites(&data);
	init_player(&data);
	init_data_ending(&data);
	data.map = get_map(&map, argv);
	data.player->pos[0] = data.map.player_pos[0] * 256;
	data.player->pos[1] = data.map.player_pos[1] * 256;
	tick(&data);
	event(&data);
	mlx_loop_hook(data.mlx_ptr, tick, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
