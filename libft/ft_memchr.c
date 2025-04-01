/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:39:03 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/31 08:51:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	character;
	unsigned char	*s_temp;

	i = 0;
	character = (unsigned char) c;
	s_temp = (unsigned char *) s;
	while (i < n)
	{
		if (s_temp[i] == character)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
