/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:09:05 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/11 12:10:12 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

void	fps(t_data *data)
{
	long long	now;

	now = millitimestamp();
	if (now > data->lm)
	{
		data->fps = 960 / (now - data->lm);
		data->lm = now;
	}
}

void	show_fps(t_data *data)
{
	char	*debug_msg;
	char	*fps;

	fps = ft_itoa(data->fps);
	debug_msg = ft_strjoin("FPS: ", fps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, 11001101, debug_msg);
	free(fps);
	free(debug_msg);
}
