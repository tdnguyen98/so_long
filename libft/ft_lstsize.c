/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:04:42 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/07 13:24:52 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		sum;
	t_list	*tmp;

	sum = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		sum++;
	}
	return (sum);
}
