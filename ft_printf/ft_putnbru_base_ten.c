/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_base_ten.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:28:52 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:39:41 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru_base_ten(unsigned int nbr, char *symboles)
{
	long	n;
	int		sum;

	n = nbr;
	sum = 0;
	if (n >= 10)
	{
		sum += ft_putnbru_base_ten(n / 10, symboles);
		if (sum < 0)
			return (-1);
	}
	if (ft_putchar_pf(symboles[n % 10]) < 0)
		return (-1);
	sum++;
	return (sum);
}
