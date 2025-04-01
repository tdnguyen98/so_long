/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:29:56 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 13:56:21 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data, void **sprite_type, int nbr, int type);
char	*get_path(int type, int i);

void	init_sprites(t_data *data)
{
	data->sprites.img_width = 256;
	data->sprites.img_height = 256;
	load_sprites(data, data->sprites.player, SPRITES_PLAYER, 0);
	load_sprites(data, data->sprites.foe, SPRITES_FOE, 1);
	load_sprites(data, data->sprites.exit, SPRITES_EXIT, 2);
	load_sprites(data, data->sprites.collectible, SPRITES_COLLECT, 3);
	load_sprites(data, data->sprites.background, SPRITES_BACKGROUND, 4);
	load_sprites(data, data->sprites.hud, SPRITES_HUD, 5);
}

void	load_sprites(t_data *data, void **sprite_type, int nbr, int type)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (i < nbr)
	{
		path = get_path(type, i);
		if (path == NULL)
			exit(1);
		sprite_type[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				path, &data->sprites.img_width, &data->sprites.img_height);
		if (sprite_type == NULL)
			exit(1);
		free(path);
		i++;
	}
}

char	*get_path(int type, int i)
{
	static char	path[6][50] = {
		"textures/player/player_",
		"textures/foe/foe_",
		"textures/exit/exit_",
		"textures/collectible/collectibles_",
		"textures/background/background_",
		"textures/hud/hud_"
	};
	char		*str1;
	char		*str2;
	char		*nbr;

	str1 = NULL;
	str2 = NULL;
	nbr = ft_itoa(i);
	str1 = ft_strjoin(path[type], nbr);
	str2 = ft_strjoin(str1, ".xpm");
	free(str1);
	free(nbr);
	return (str2);
}
