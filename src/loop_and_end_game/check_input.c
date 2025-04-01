/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:05:36 by thenguye          #+#    #+#             */
/*   Updated: 2025/04/01 20:09:17 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 0, close_game, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_released, data);
}

int	key_released(int keysym, t_data *data)
{
	reset_move(data, keysym);
	return (1);
}

int	key_pressed(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
	{
		data->ending[0] = 150;
		close_game(data);
	}
	set_move(data, keysym);
	return (1);
}
