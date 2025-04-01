/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:48:46 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/30 11:45:53 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*tab;

	tab = malloc(sizeof(t_list));
	if (tab == NULL)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
