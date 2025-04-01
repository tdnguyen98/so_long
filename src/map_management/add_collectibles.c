/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_collectibles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:22:44 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/14 11:30:14 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_collectibles(t_map *map)
{
	int		*tab;
	int		count;
	int		i;

	tab = put_pos_in_tab(map);
	count = 0;
	i = 0;
	while ((count - map->collectible) < 0)
	{
		if (count == 0)
			create_staff(map, tab[i + 1], tab[i]);
		else if (count == 1)
			create_scroll(map, tab[i + 1], tab[i], 'o');
		else if (count == 2)
			create_scroll(map, tab[i + 1], tab[i], 'h');
		else if (count >= 3)
			create_collectible(map, tab[i + 1], tab[i]);
		count++;
		i += 2;
	}
	free(tab);
}

int	*put_pos_in_tab(t_map *map)
{
	t_list	*first;
	int		*tab;
	int		i;

	first = map->collect_pos;
	i = 0;
	while (map->collect_pos != NULL)
	{
		map->collect_pos = map->collect_pos->next;
		i++;
	}
	map->collect_pos = first;
	tab = calloc(i, sizeof(int));
	i = 0;
	while (map->collect_pos != NULL)
	{
		tab[i++] = map->collect_pos->content;
		map->collect_pos = map->collect_pos->next;
	}
	free_stash(first);
	return (tab);
}
