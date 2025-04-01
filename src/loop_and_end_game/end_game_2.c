/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:29 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 14:40:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data_ending(t_data *data)
{
	data->ending[0] = 0;
	data->ending[1] = 0;
	data->ending[2] = 0;
}

void	display_ending(t_data *data)
{
	data->ending[0]++;
	if (data->ending[1] == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.hud[61], 0, 0);
	else if (data->ending[2] == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.hud[62], 0, 0);
}

void	free_staff(t_staff *to_free)
{
	t_staff	*current;

	current = to_free;
	free(current);
}

void	free_scroll(t_scroll *to_free)
{
	t_scroll	*current;

	current = to_free;
	free(current);
}

void	free_collect(t_collect *to_free)
{
	t_collect	*current;
	t_collect	*next;

	current = to_free;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}
