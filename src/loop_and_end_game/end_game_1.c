/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:07:06 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/20 12:47:22 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	if (data->ending[0] >= 150 || (data->ending[1] == 0 && data->ending[0] == 0
			&& data->ending[2] == 0))
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->collision != NULL)
			free_collision(data->collision);
		if (data->map.foe != NULL)
			free_foe(data->map.foe);
		if (data->map.scroll != NULL)
			free_scroll(data->map.scroll);
		if (data->map.exit != NULL)
			free_exit(data->map.exit);
		if (data->map.collect != NULL)
			free_collect(data->map.collect);
		if (data->map.staff != NULL)
			free_staff(data->map.staff);
		if (data->map.trap != NULL)
			free_trap(data->map.trap);
		free_map(&data->map);
		free_player(data->player);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

void	free_collision(t_collision *no_zone)
{
	t_collision	*current;
	t_collision	*next;

	current = no_zone;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	free_foe(t_foe *to_free)
{
	t_foe	*current;
	t_foe	*next;

	current = to_free;
	while (current)
	{
		free_projectiles(current);
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	free_projectiles(t_foe *foe)
{
	if (foe->projectile1 != NULL)
		free(foe->projectile1);
	if (foe->projectile2 != NULL)
		free(foe->projectile2);
	if (foe->projectile3 != NULL)
		free(foe->projectile3);
}

void	free_trap(t_trap *to_free)
{
	t_trap	*current;
	t_trap	*next;

	current = to_free;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}
