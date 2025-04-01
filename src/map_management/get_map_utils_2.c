/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:21:21 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 00:26:19 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	create_interior_map(t_map *map, int row, int col)
{
	static char	*str[] = {"Xepshoc0", "ABCDEFGHIJKLMNOP1234"};

	if (is_block_a(map, row, col, str))
		return ('A');
	if (is_block_b(map, row, col, str))
		return ('B');
	if (is_block_c(map, row, col, str))
		return ('C');
	if (is_block_d(map, row, col, str))
		return ('D');
	if (is_block_e(map, row, col, str))
		return ('E');
	if (is_block_f(map, row, col, str))
		return ('F');
	if (is_block_g(map, row, col, str))
		return ('G');
	if (is_block_h(map, row, col, str))
		return ('H');
	return (create_interior_map_2(map, row, col, str));
}

char	create_interior_map_2(t_map *map, int row, int col, char **str)
{
	if (is_block_i(map, row, col, str))
		return ('I');
	if (is_block_j(map, row, col, str))
		return ('J');
	if (is_block_k(map, row, col, str))
		return ('K');
	if (is_block_l(map, row, col, str))
		return ('L');
	if (is_block_m(map, row, col, str))
		return ('M');
	if (is_block_n(map, row, col, str))
		return ('N');
	if (is_block_o(map, row, col, str))
		return ('O');
	if (is_block_p(map, row, col, str))
		return ('P');
	return ('B');
}

void	are_exit_scroll_staff_on_ground(t_map *map)
{
	t_exit		*tmp;
	t_scroll	*tmp2;
	t_staff		*tmp3;

	tmp = map->exit;
	tmp2 = map->scroll;
	tmp3 = map->staff;
	if (!is_on_ground(map, (tmp->pos[1] / 256) + 1, (tmp->pos[0] / 256)))
		map_error(map, 10);
	if (!is_on_ground(map, (tmp2->orb_pos[1] / 256) + 1,
			(tmp2->orb_pos[0] / 256)))
		map_error(map, 10);
	if (!is_on_ground(map, (tmp2->heal_pos[1] / 256) + 1,
			(tmp2->heal_pos[0] / 256)))
		map_error(map, 10);
	if (!is_on_ground(map, (tmp3->pos[1] / 256) + 1,
			(tmp3->pos[0] / 256)))
		map_error(map, 10);
}

int	is_on_ground(t_map *map, int y, int x)
{
	static char	str[] = {"1ACGIMKNO"};
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (map->map[y][x] == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
