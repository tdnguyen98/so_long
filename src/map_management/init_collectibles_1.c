/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:20:11 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 11:09:02 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_staff(t_map *map, int x, int y)
{
	map->map[y][x] = 's';
	map->staff = malloc(sizeof(t_staff));
	if (map->staff == NULL)
	{
		free_map(map);
		exit(1);
	}
	map->staff->staff = 1;
	map->staff->staff_offset = 0;
	map->staff->pos[0] = x * 256;
	map->staff->pos[1] = y * 256;
	map->staff->pos_base[0] = x * 256;
	map->staff->pos_base[1] = y * 256;
	map->staff->pos_top_left[0] = map->staff->pos[0] + 100;
	map->staff->pos_top_left[1] = map->staff->pos[1] + 85;
	map->staff->pos_top_right[0] = map->staff->pos[0] + 148;
	map->staff->pos_top_right[1] = map->staff->pos[1] + 85;
	map->staff->pos_bottom_left[0] = map->staff->pos[0] + 100;
	map->staff->pos_bottom_left[1] = map->staff->pos[1] + 178;
	map->staff->pos_bottom_right[0] = map->staff->pos[0] + 148;
	map->staff->pos_bottom_right[1] = map->staff->pos[1] + 178;
}

void	create_scroll(t_map *map, int x, int y, char c)
{
	if (map->scroll == NULL)
	{
		map->scroll = malloc(sizeof(t_scroll));
		if (map->scroll == NULL)
		{
			free_map(map);
			exit(1);
		}
	}
	if (c == 'o')
		init_scroll_orb(map, x, y);
	else if (c == 'h')
		init_scroll_heal(map, x, y);
}

void	init_scroll_orb(t_map *map, int x, int y)
{
	map->map[y][x] = 'o';
	map->scroll->orb = 1;
	map->scroll->orb_offset = 0;
	map->scroll->o_pos_base[0] = x * 256;
	map->scroll->o_pos_base[1] = y * 256;
	map->scroll->orb_pos[0] = x * 256;
	map->scroll->orb_pos[1] = y * 256;
	map->scroll->o_pos_top_left[0] = map->scroll->orb_pos[0] + 112;
	map->scroll->o_pos_top_left[1] = map->scroll->orb_pos[1] + 129;
	map->scroll->o_pos_top_right[0] = map->scroll->orb_pos[0] + 144;
	map->scroll->o_pos_top_right[1] = map->scroll->orb_pos[1] + 129;
	map->scroll->o_pos_bottom_left[0] = map->scroll->orb_pos[0] + 112;
	map->scroll->o_pos_bottom_left[1] = map->scroll->orb_pos[1] + 160;
	map->scroll->o_pos_bottom_right[0] = map->scroll->orb_pos[0] + 144;
	map->scroll->o_pos_bottom_right[1] = map->scroll->orb_pos[1] + 160;
}

void	init_scroll_heal(t_map *map, int x, int y)
{
	map->map[y][x] = 'h';
	map->scroll->heal = 1;
	map->scroll->heal_offset = 0;
	map->scroll->h_pos_base[0] = x * 256;
	map->scroll->h_pos_base[1] = y * 256;
	map->scroll->heal_pos[0] = x * 256;
	map->scroll->heal_pos[1] = y * 256;
	map->scroll->h_pos_top_left[0] = map->scroll->heal_pos[0] + 112;
	map->scroll->h_pos_top_left[1] = map->scroll->heal_pos[1] + 129;
	map->scroll->h_pos_top_right[0] = map->scroll->heal_pos[0] + 144;
	map->scroll->h_pos_top_right[1] = map->scroll->heal_pos[1] + 129;
	map->scroll->h_pos_bottom_left[0] = map->scroll->heal_pos[0] + 112;
	map->scroll->h_pos_bottom_left[1] = map->scroll->heal_pos[1] + 160;
	map->scroll->h_pos_bottom_right[0] = map->scroll->heal_pos[0] + 144;
	map->scroll->h_pos_bottom_right[1] = map->scroll->heal_pos[1] + 160;
}

void	create_collectible(t_map *map, int x, int y)
{
	t_collect	*tmp;

	map->map[y][x] = 'c';
	tmp = malloc(sizeof(t_collect));
	if (tmp == NULL)
	{
		free_map(map);
		exit(1);
	}
	tmp->light = 1;
	tmp->light_offset = 0;
	tmp->light_pos[0] = (x * 256) + (rand() % 50);
	tmp->light_pos[1] = (y * 256) + (rand() % 50);
	tmp->pos_top_left[0] = tmp->light_pos[0] + 112;
	tmp->pos_top_left[1] = tmp->light_pos[1] + 129;
	tmp->pos_top_right[0] = tmp->light_pos[0] + 144;
	tmp->pos_top_right[1] = tmp->light_pos[1] + 129;
	tmp->pos_bottom_left[0] = tmp->light_pos[0] + 112;
	tmp->pos_bottom_left[1] = tmp->light_pos[1] + 160;
	tmp->pos_bottom_right[0] = tmp->light_pos[0] + 144;
	tmp->pos_bottom_right[1] = tmp->light_pos[1] + 160;
	tmp->next = NULL;
	ft_lstadd_back_collect(&map->collect, tmp);
}
