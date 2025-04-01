/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:55:49 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/31 09:08:54 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	size_t			i;

	s1_temp = (unsigned char *) s1;
	s2_temp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return ((int) s1_temp[i] - (int) s2_temp[i]);
		i++;
	}
	return (0);
}
