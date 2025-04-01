/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:44:06 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:39:22 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned	long n, char *symboles)
{
	int		sum;

	sum = 0;
	if (n >= 16)
	{
		sum += ft_print_ptr(n / 16, symboles);
		if (sum < 0)
			return (-1);
	}
	if (ft_putchar_pf(symboles[n % 16]) < 0)
		return (-1);
	sum++;
	return (sum);
}

int	ft_putpointer(unsigned	long n, char *symboles)
{
	int		sum;

	sum = 0;
	sum = ft_putstr_pf("0x");
	if (sum < 0)
		return (-1);
	sum += ft_print_ptr(n, symboles);
	if (sum < 0)
		return (-1);
	return (sum);
}
