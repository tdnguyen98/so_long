/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:15:00 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/30 11:56:46 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_src;
	size_t	length_dst;
	size_t	i;
	size_t	n;

	length_src = ft_strlen(src);
	length_dst = ft_strlen(dst);
	i = 0;
	n = length_dst;
	if (dstsize <= length_dst)
		length_dst = dstsize;
	else if ((length_src + length_dst + 1) < dstsize)
	{
		while (i < length_src)
			dst[n++] = src[i++];
	}
	else
	{
		while (i < (dstsize - length_dst - 1))
			dst[n++] = src[i++];
	}
	dst[n] = '\0';
	return (length_dst + length_src);
}
