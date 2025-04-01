/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:33:23 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/14 14:33:28 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dead_collision_foe(t_foe *foe)
{
	foe->pos_top_left[0] = foe->pos[0] + 100;
	foe->pos_top_left[1] = foe->pos[1] + 230;
	foe->pos_top_right[0] = foe->pos[0] + 136;
	foe->pos_top_right[1] = foe->pos[1] + 230;
	foe->pos_bottom_left[0] = foe->pos[0] + 100;
	foe->pos_bottom_left[1] = foe->pos[1] + 255;
	foe->pos_bottom_right[0] = foe->pos[0] + 136;
	foe->pos_bottom_right[1] = foe->pos[1] + 255;
}
