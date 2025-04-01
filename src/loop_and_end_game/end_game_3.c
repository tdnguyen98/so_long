/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:40:00 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/20 12:48:03 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_exit *to_free)
{
	t_exit	*current;

	current = to_free;
	free(current);
}

void	free_player(t_player *to_free)
{
	t_player	*current;

	if (to_free->projectile1 != NULL)
		free(to_free->projectile1);
	current = to_free;
	free(current);
}
