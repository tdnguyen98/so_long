/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_cast_spell.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:40:32 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 23:44:24 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_cast_spell(t_data *data)
{
	if (data->player->direction == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[45], 512, 512);
	}
	else if (data->player->direction == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player[44], 512, 512);
	}
}
