/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:37:36 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/25 13:53:35 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if ((dst == (void *)0) && (src == (void *)0))
		return (dst);
	temp_src = (unsigned char *) src;
	temp_dst = (unsigned char *) dst;
	while (n--)
	{
		*(temp_dst++) = *(temp_src++);
	}
	return (dst);
}
