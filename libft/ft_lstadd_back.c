/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:35:05 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/25 11:39:59 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nouveau)
{
	t_list	*back;

	if (!nouveau)
		return ;
	back = ft_lstlast(*lst);
	if (!*lst)
		*lst = nouveau;
	else
		back->next = nouveau;
}
