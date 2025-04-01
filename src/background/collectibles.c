/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:35:28 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/14 11:20:27 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collectibles(t_data *data)
{
	if (data->map.staff != NULL)
		draw_staff(data);
	if (data->map.scroll != NULL)
	{
		draw_scroll_orb(data);
		draw_scroll_heal(data);
	}
	if (data->map.collect != NULL)
		draw_light(data);
}
