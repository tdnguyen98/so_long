/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:02:55 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/25 10:31:06 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}	t_list_gnl;

char		*get_next_line(int fd);
void		ft_free_stash(t_list_gnl *stash);
int			ft_read_and_stash(int fd, t_list_gnl **stash);
void		ft_add_to_stash(t_list_gnl **stash, char *buf, int nbr_read);
char		*ft_extract_line_from_stash(t_list_gnl *stash, char *line);
char		*ft_malloc_line(t_list_gnl *stash);
int			clean_used_stash(t_list_gnl	**stash);
int			ft_find_new_line(t_list_gnl *stash);
t_list_gnl	*ft_lstlast_gnl(t_list_gnl *lst);
int			ft_strlen_gnl(const char *s);

#endif
