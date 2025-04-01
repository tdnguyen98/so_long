/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:26:51 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 22:27:13 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	aabb_trap(t_data *data, t_trap *collision, int x, int y)
{
	if (data->player->pos_top_left[0] < collision->pos_bottom_right[0] - x
		&& data->player->pos_top_right[0] > collision->pos_top_left[0] - x
		&& data->player->pos_top_left[1] < collision->pos_bottom_right[1] - y
		&& data->player->pos_bottom_left[1] > collision->pos_top_right[1] - y)
		return (1);
	return (0);
}
