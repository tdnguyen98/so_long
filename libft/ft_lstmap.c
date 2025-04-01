/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:38 by thenguye          #+#    #+#             */
/*   Updated: 2023/11/08 21:41:09 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*new_content;

	if (!lst)
		return (NULL);
	tmp = NULL;
	new_content = NULL;
	new = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_content = ft_lstnew(tmp);
		if (!new_content)
		{
			del (tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, new_content);
		lst = lst->next;
	}
	return (new);
}
