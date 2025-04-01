/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_foe_projectiles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:57:22 by thenguye          #+#    #+#             */
/*   Updated: 2024/03/12 21:12:32 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_foe_projectiles(char c)
{
	static char	*char_utils = {
		"pZXocehs"
	};
	int			i;

	i = 0;
	while (char_utils[i] != '\0')
	{
		if (c == char_utils[i])
			return (1);
		i++;
	}
	return (0);
}
