/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_trap_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:02:40 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:15:35 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_trap(t_map *map, int col, int row, int dir)
{
	t_trap	*tmp;

	tmp = malloc(sizeof(t_trap));
	if (tmp == NULL)
		return ;
	if (dir == 19)
		map->map[row][col] = 'Q';
	else if (dir == 22)
		map->map[row][col] = 'R';
	else if (dir == 25)
		map->map[row][col] = 'S';
	tmp = get_trap_pos_collision(tmp, col, row, dir);
	tmp->delay = 0;
	tmp->is_triggered = 0;
	tmp->dir = dir;
	tmp->next = NULL;
	ft_lstadd_back_trap(&map->trap, tmp);
}

t_trap	*get_trap_pos_collision(t_trap *tmp, int col, int row, int dir)
{
	if (dir == 19)
		tmp = trap_right_trigger_collision(tmp, col, row);
	else if (dir == 22)
		tmp = trap_up_trigger_collision(tmp, col, row);
	else if (dir == 25)
		tmp = trap_left_trigger_collision(tmp, col, row);
	return (tmp);
}

t_trap	*trap_right_trigger_collision(t_trap *tmp, int col, int row)
{
	tmp->pos[0] = (col * 256) - 179;
	tmp->pos[1] = (row * 256);
	tmp->pos_top_left[0] = tmp->pos[0] + 94;
	tmp->pos_top_left[1] = tmp->pos[1];
	tmp->pos_top_right[0] = tmp->pos[0] + 256;
	tmp->pos_top_right[1] = tmp->pos[1];
	tmp->pos_bottom_left[0] = tmp->pos[0] + 94;
	tmp->pos_bottom_left[1] = tmp->pos[1] + 256;
	tmp->pos_bottom_right[0] = tmp->pos[0] + 256;
	tmp->pos_bottom_right[1] = tmp->pos[1] + 256;
	return (tmp);
}

t_trap	*trap_up_trigger_collision(t_trap *tmp, int col, int row)
{
	tmp->pos[0] = (col * 256);
	tmp->pos[1] = (row * 256) + 179;
	tmp->pos_top_left[0] = tmp->pos[0];
	tmp->pos_top_left[1] = tmp->pos[1];
	tmp->pos_top_right[0] = tmp->pos[0] + 256;
	tmp->pos_top_right[1] = tmp->pos[1];
	tmp->pos_bottom_left[0] = tmp->pos[0];
	tmp->pos_bottom_left[1] = tmp->pos[1] + 162;
	tmp->pos_bottom_right[0] = tmp->pos[0] + 256;
	tmp->pos_bottom_right[1] = tmp->pos[1] + 162;
	return (tmp);
}

t_trap	*trap_left_trigger_collision(t_trap *tmp, int col, int row)
{
	tmp->pos[0] = (col * 256) + 179;
	tmp->pos[1] = (row * 256);
	tmp->pos_top_left[0] = tmp->pos[0];
	tmp->pos_top_left[1] = tmp->pos[1];
	tmp->pos_top_right[0] = tmp->pos[0] + 162;
	tmp->pos_top_right[1] = tmp->pos[1];
	tmp->pos_bottom_left[0] = tmp->pos[0];
	tmp->pos_bottom_left[1] = tmp->pos[1] + 256;
	tmp->pos_bottom_right[0] = tmp->pos[0] + 162;
	tmp->pos_bottom_right[1] = tmp->pos[1] + 256;
	return (tmp);
}
