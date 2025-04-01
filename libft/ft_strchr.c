/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:02 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/30 13:53:09 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;
	int				i;

	character = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == character)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == character)
		return ((char *) &s[i]);
	return (NULL);
}
