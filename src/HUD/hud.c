/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:18:25 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/18 13:04:33 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_hud(t_data *data)
{
	draw_hud_life(data);
	draw_hud_mana(data);
	draw_hud_steps(data);
}

void	draw_hud_life(t_data *data)
{
	char	*msg;
	char	*msg2;
	char	*life;

	life = ft_itoa(data->player->life_points);
	msg = ft_strjoin("Life:         ", life);
	msg2 = ft_strjoin(msg, "/300");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.hud[data->player->life_points / 5], 20, 36);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 50,
		encode_rgb(255, 0, 0), msg2);
	free(life);
	free(msg);
	free(msg2);
}

void	draw_hud_mana(t_data *data)
{
	char	*msg;
	char	*msg2;
	char	*mana;

	mana = ft_itoa(data->player->mana_points / 3);
	msg = ft_strjoin("Mana:         ", mana);
	msg2 = ft_strjoin(msg, "/300");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.hud[data->player->mana_points / 15], 20, 56);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 70,
		encode_rgb(0, 0, 255), msg2);
	free(mana);
	free(msg);
	free(msg2);
}

void	draw_hud_steps(t_data *data)
{
	char	*msg;
	char	*steps;

	steps = ft_itoa((data->steps) / 11);
	msg = ft_strjoin("Steps:         ", steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 90,
		encode_rgb(255, 255, 255), msg);
	free(steps);
	free(msg);
}

int	encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
