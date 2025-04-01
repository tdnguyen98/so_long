/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:09:26 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/19 00:11:43 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_map *map, int error)
{
	static const char	error_tab[11][100] = {
		"Error - can't open map\n",
		"Error - map must be a rectangle\n",
		"Error - map must be surrounded by walls\n",
		"Error - map must have one player\n",
		"Error - map must have at least one collectible\n",
		"Error - map must have one exit\n",
		"Error - map must only contain valid characters\n",
		"Error - map accessibility errors\n",
		"Error - map wrong extension\n",
		"Error - map empty\n",
		"Error - exit, staff or scroll not on ground\n"
	};

	ft_printf("%s", error_tab[error]);
	free_map(map);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->collect_pos != NULL)
		free_stash(map->collect_pos);
}

void	free_stash(t_list *pos)
{
	t_list	*current;
	t_list	*next;

	current = pos;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}
