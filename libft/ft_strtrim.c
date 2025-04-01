/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:18 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/02 10:46:29 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_character(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_removable(char const *s1, char const *set, int *start)
{
	int		i;
	int		len;
	int		tmp_len;

	i = 0;
	len = (int) ft_strlen(s1);
	tmp_len = len;
	while (i < len && check_character(s1[i], set))
	{
		len--;
		*start += 1;
		i++;
	}
	i = tmp_len - 1;
	while (i > 0 && check_character(s1[i], set))
	{
		len--;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		i;
	int		start;
	int		len;

	i = 0;
	start = 0;
	if ((int) ft_strlen(s1) == 0)
		return (ft_strdup(""));
	len = count_removable(s1, set, &start);
	if (len <= 0 || start >= (int) ft_strlen(s1))
		return (ft_strdup(""));
	tmp = (char *) malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s1[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
