/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:12:52 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/31 09:42:50 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[n] == 0)
		return ((char *) haystack);
	while (haystack[i] && ((i + ft_strlen(&needle[n]) - 1) < len))
	{
		if (haystack[i] == needle[n])
		{
			if (!(ft_strncmp(&haystack[i], &needle[n], ft_strlen(&needle[n]))))
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
