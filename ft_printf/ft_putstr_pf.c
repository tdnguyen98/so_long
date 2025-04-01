/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:33:22 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:40:34 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(const char *s)
{
	int	sum;

	sum = 0;
	if (!s)
	{
		sum += ft_putstr_pf("(null)");
		if (sum < 0)
			return (-1);
	}
	else
	{
		while (*s)
		{
			if (ft_putchar_pf(*s) < 0)
				return (-1);
			sum++;
			s++;
		}
	}
	return (sum);
}
