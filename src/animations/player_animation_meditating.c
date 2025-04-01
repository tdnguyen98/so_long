/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_meditating.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:42:26 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 12:44:50 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_meditating(t_data *data)
{
	int	i;

	i = 0;
	i = check_collision(data, 4);
	if (i >= 10)
	{
		data->player->levitating_move = (data->player->levitating_move + 1)
			% 20;
		if (data->player->levitating_move < 10)
			data->player->pos[1] += 1;
		else
			data->player->pos[1] -= 1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.player[18 + data->player->anim_staff_offset],
		512, 512);
}
