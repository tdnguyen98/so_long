/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:52:32 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/30 14:03:16 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	character;
	int				i;
	int				n;

	character = (unsigned char) c;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == character)
			n = i;
		i++;
	}
	if (s[n] == character)
		return ((char *) &s[n]);
	if (s[i] == character)
		return ((char *) &s[i]);
	return (NULL);
}
