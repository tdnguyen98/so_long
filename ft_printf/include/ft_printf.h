/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:17:32 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/19 15:15:21 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(const char *s);
int	ft_putnbr_base_ten(long n, char *symboles);
int	ft_putnbru_base_ten(unsigned int nbr, char *symboles);
int	ft_putnbr_hex(unsigned	int n, char *symboles);
int	ft_putpointer(unsigned	long n, char *symboles);

#endif
