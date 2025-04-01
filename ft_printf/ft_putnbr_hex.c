/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:48 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:39:57 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned	int n, char *symboles)
{
	int		sum;

	sum = 0;
	if (n >= 16)
	{
		sum += ft_putnbr_hex(n / 16, symboles);
		if (sum < 0)
			return (-1);
	}
	if (ft_putchar_pf(symboles[n % 16]) < 0)
		return (-1);
	sum++;
	return (sum);
}
