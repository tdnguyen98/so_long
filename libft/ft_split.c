/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:14:29 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/07 12:53:21 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_of_word(char const *s, char sep, int start)
{
	int	sum;

	sum = 0;
	while (s[start] != sep && s[start])
	{
		sum++;
		start++;
	}
	return (sum);
}

static void	get_start_and_length(char const *s, char sep, int *tab)
{
	int	i;
	int	n;
	int	flag;

	i = 0;
	n = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != sep && flag == 0)
		{
			flag = 1;
			tab[n++] = i;
			tab[n] = length_of_word(s, sep, tab[n - 1]);
			n++;
		}
		else if (s[i] == sep)
			flag = 0;
		i++;
	}
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	nbr_words;
	int	flag;

	i = 0;
	flag = 0;
	nbr_words = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			nbr_words++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (nbr_words);
}

static char	**add_word_in_strings(int *tab, char **tmp, const char *s, int nbr)
{
	int	i;
	int	n;
	int	ok;

	i = 0;
	n = 0;
	ok = 0;
	while (i < nbr && !ok)
	{
		tmp[i] = (char *) ft_substr(s, tab[n], tab[n + 1]);
		if (tmp[i] == NULL)
		{
			while (ok < i)
				free(tmp[ok++]);
			free(tmp);
			free(tab);
			return (NULL);
		}
		i++;
		n += 2;
	}
	free(tab);
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		*start_pos;
	int		nbr;

	nbr = count_words(s, c);
	tmp = ft_calloc((nbr + 1), sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	start_pos = (int *) malloc((nbr * 2) * sizeof(long int));
	if (start_pos == NULL)
	{
		free(start_pos);
		free(tmp);
		return (NULL);
	}
	get_start_and_length(s, c, start_pos);
	tmp = add_word_in_strings(start_pos, tmp, s, nbr);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
