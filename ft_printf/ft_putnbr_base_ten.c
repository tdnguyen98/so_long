/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ten.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:39:46 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:40:10 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_ten(long n, char *symboles)
{
	int		sum;
	long	nbr;

	sum = 0;
	nbr = n;
	if (nbr < 0)
	{
		if (ft_putchar_pf('-') < 0)
			return (-1);
		sum++;
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		sum += ft_putnbr_base_ten(nbr / 10, symboles);
		if (sum < 0)
			return (-1);
	}
	if (ft_putchar_pf(symboles[nbr % 10]) < 0)
		return (-1);
	sum++;
	return (sum);
}
