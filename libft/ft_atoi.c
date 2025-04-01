/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:48:05 by thenguye          #+#    #+#             */
/*   Updated: 2023/10/31 11:32:09 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	sum;

	i = 0;
	neg = 1;
	sum = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (ft_isdigit((int) str[i]))
	{
		while (ft_isdigit((int) str[i]))
		{
			sum = (sum * 10) + (str[i] - 48);
			i++;
		}
		return ((sum * neg));
	}
	return (0);
}
