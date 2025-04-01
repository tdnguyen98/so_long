/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:49:50 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/09 09:48:29 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, va_list args)
{
	int	size;

	size = 0;
	if (*format == 'c')
		size = ft_putchar_pf(va_arg(args, int));
	else if (*format == 's')
		size = ft_putstr_pf(va_arg(args, char *));
	else if (*format == 'p')
		size = ft_putpointer(va_arg(args, unsigned long), "0123456789abcdef");
	else if ((*format == 'd') || (*format == 'i'))
		size = ft_putnbr_base_ten(va_arg(args, int), "0123456789");
	else if (*format == 'u')
		size = ft_putnbru_base_ten(va_arg(args, unsigned int), "0123456789");
	else if (*format == 'x')
		size = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		size = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
		size = ft_putchar_pf('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum;
	int		size_args;

	va_start(args, format);
	sum = 0;
	while (*format)
	{
		if (*format == '%')
		{
			size_args = ft_check_format(++format, args);
			if (size_args < 0)
				return (-1);
			sum += size_args;
		}
		else
		{
			if (ft_putchar_pf(*format) < 0)
				return (-1);
			sum++;
		}
		format++;
	}
	va_end(args);
	return (sum);
}
