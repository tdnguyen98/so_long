/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:52:28 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:14:30 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile_trap(t_data *data, int x, int y, int dir)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.background[dir], x, y);
}
