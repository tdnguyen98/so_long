/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:21:03 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/06 20:25:50 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size += 1;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	get_multiple(int size, long nbr)
{
	int	i;
	int	multiple;

	i = 0;
	multiple = 1;
	if (nbr < 0)
		size--;
	while (i < size - 1)
	{
		multiple *= 10;
		i++;
	}
	return (multiple);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	int		size;
	char	*arg;
	int		multiple;

	i = 0;
	nbr = n;
	size = ft_size(nbr);
	multiple = get_multiple(size, nbr);
	arg = (char *) ft_calloc((size + 1), sizeof(char));
	if (arg == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		arg[i++] = '-';
	}
	while (i < size)
	{
		arg[i++] = (nbr / multiple) + '0';
		nbr %= multiple;
		multiple /= 10;
	}
	return (arg);
}
