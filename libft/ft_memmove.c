/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:59:05 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/30 10:31:53 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	n;

	if ((dst == (void *)0) && (src == (void *)0))
		return (NULL);
	temp_dst = (char *) dst;
	temp_src = (char *) src;
	n = 0;
	if (dst > src)
	{
		while (len--)
		{
			temp_dst[len] = temp_src[len];
		}
	}
	else
	{
		while (n < len)
		{
			temp_dst[n] = temp_src[n];
			n++;
		}
	}
	return (dst);
}
