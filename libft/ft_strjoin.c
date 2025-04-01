/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:29:23 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/01 15:47:36 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*tmp;
	size_t	i;

	i = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	tmp = (char *) malloc((s1_length + s2_length + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (i < (s1_length + s2_length))
	{
		if (i < s1_length)
			tmp[i] = s1[i];
		else
			tmp[i] = s2[i - s1_length];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
