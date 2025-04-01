/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_foe_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:30:18 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:29:37 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_foe	*get_foe_pos_and_collision(t_foe *tmp, int col, int row);

void	add_enemies(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < (int)map->height)
	{
		x = 1;
		while (x < (int)map->width - 1)
		{
			if (map->map[y][x] == '1' && map->map[y - 1][x] == 'X'
				&& map->map[y - 2][x] == 'X')
			{
				map->map[y - 1][x] = 'Z';
				get_foe(map, x, y - 1);
				x = map->width;
			}
			x++;
		}
		y++;
	}
}

void	get_foe(t_map *map, int col, int row)
{
	t_foe	*tmp;

	tmp = malloc(sizeof(t_foe));
	if (tmp == NULL)
		return ;
	tmp = get_foe_pos_and_collision(tmp, col, row);
	tmp->move[0] = 0;
	tmp->move[1] = 1;
	tmp->direction = 0;
	tmp->is_attacking = 0;
	tmp->is_dead = 0;
	tmp->anim_delay = 0;
	tmp->attack_delay = 0;
	tmp->cooldown = 0;
	tmp->projectile1 = NULL;
	tmp->projectile2 = NULL;
	tmp->projectile3 = NULL;
	tmp->next = NULL;
	ft_lstadd_back_foe(&map->foe, tmp);
}

t_foe	*get_foe_pos_and_collision(t_foe *tmp, int col, int row)
{
	tmp->pos[0] = (col * 256);
	tmp->pos[1] = (row * 256);
	tmp->pos_top_left[0] = tmp->pos[0] + 100;
	tmp->pos_top_left[1] = tmp->pos[1] + 163;
	tmp->pos_top_right[0] = tmp->pos[0] + 136;
	tmp->pos_top_right[1] = tmp->pos[1] + 163;
	tmp->pos_bottom_left[0] = tmp->pos[0] + 100;
	tmp->pos_bottom_left[1] = tmp->pos[1] + 255;
	tmp->pos_bottom_right[0] = tmp->pos[0] + 136;
	tmp->pos_bottom_right[1] = tmp->pos[1] + 255;
	return (tmp);
}

int	probability(int prob)
{
	int	random_number;

	random_number = rand() % 100;
	return (random_number < prob);
}
