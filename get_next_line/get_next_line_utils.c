/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:02:51 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/25 11:43:49 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

int	ft_find_new_line(t_list_gnl *stash)
{
	int			i;
	t_list_gnl	*last;

	i = 0;
	if (!stash)
		return (0);
	last = ft_lstlast_gnl(stash);
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list_gnl	*ft_lstlast_gnl(t_list_gnl *lst)
{
	t_list_gnl	*tmp;
	t_list_gnl	*last;

	if (!lst)
		return (NULL);
	tmp = lst;
	last = lst;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
			last = last->next;
	}
	return (last);
}

char	*ft_malloc_line(t_list_gnl *stash)
{
	int		i;
	int		j;
	int		flag;
	char	*tmp;

	j = 0;
	flag = 1;
	if (!stash)
		return (NULL);
	while (stash && flag)
	{
		i = 0;
		while (stash->content[i] && flag)
		{
			if (stash->content[i] == '\n')
				flag = 0;
			i++;
			j++;
		}
		stash = stash->next;
	}
	tmp = malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	ft_free_stash(t_list_gnl *stash)
{
	t_list_gnl	*current;
	t_list_gnl	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
