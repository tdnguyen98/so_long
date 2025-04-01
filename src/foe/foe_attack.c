/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_attack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:06:29 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 13:06:50 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_foe	*is_foe_attacking_01(t_foe *foe, t_data *data)
{
	if (aabb_foe(data, foe, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)))
	{
		foe->is_attacking = 1;
		data->player->life_points -= 1;
	}
	return (foe);
}

t_foe	*is_foe_attacking_02(t_foe *foe, t_data *data)
{
	if (aabb_foe_distance(data, foe, (data->player->pos[0] - 512),
			(data->player->pos[1] - 512)) && foe->is_attacking == 0
		&& foe->cooldown == 0 && (foe->projectile1 == NULL
			&& foe->projectile2 == NULL && foe->projectile3 == NULL))
	{
		foe->cooldown = 1;
		foe->is_attacking = 2;
	}
	return (foe);
}
