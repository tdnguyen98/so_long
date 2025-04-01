/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:02:17 by thenguye          #+#    #+#             */
/*   Updated: 2024/01/25 11:47:28 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_gnl	*stash;
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read_and_stash(fd, &stash))
	{
		ft_free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line_from_stash(stash, line);
	if (!line)
		return (NULL);
	if (!clean_used_stash(&stash))
		return (NULL);
	if (line[0] == '\0')
	{
		ft_free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/*
	This function read in the file nbyte (depending of the BUFFERR_SIZE)
	and store what it read in the chained list stash until it find a
	newline character in the stash.
	return 0 if there is an error with malloc or read
	return 1 if the line is in the stash and there is a newline character
*/
int	ft_read_and_stash(int fd, t_list_gnl **stash)
{
	char	*buf;
	int		nbr_read;

	nbr_read = 1;
	while (!ft_find_new_line(*stash) && nbr_read != 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (0);
		nbr_read = read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && nbr_read == 0) || nbr_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[nbr_read] = '\0';
		ft_add_to_stash(stash, buf, nbr_read);
		free(buf);
	}
	return (1);
}

/*
	This function add each readable byte of the file in a new element
	in the last of the chained list stash.
*/
void	ft_add_to_stash(t_list_gnl **stash, char *buf, int nbr_read)
{
	t_list_gnl	*new;
	t_list_gnl	*last;
	int			i;

	i = 0;
	new = malloc(sizeof(t_list_gnl));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc((ft_strlen_gnl(buf) + 1) * sizeof(char));
	if (!new->content)
		return ;
	while (buf[i] && i < nbr_read)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	last = ft_lstlast_gnl(*stash);
	if (!(*stash))
		*stash = new;
	else
		last->next = new;
}

/*
	This function extract the characters from the different elements
	of the stash and put them in an array of char. It uses the ft_malloc
	line to malloc the array line with the good amount of characters
	and then add the characters into the array line.
	return NULL if there is an error with the malloc of "line"
	return the array of char "line" if everything worked well
*/
char	*ft_extract_line_from_stash(t_list_gnl *stash, char *line)
{
	int	i;
	int	len;
	int	flag;

	len = 0;
	flag = 1;
	line = ft_malloc_line(stash);
	if (!line)
		return (NULL);
	while (stash)
	{
		i = 0;
		while (stash->content[i] && flag)
		{
			if (stash->content[i] == '\n')
				flag = 0;
			line[len] = stash->content[i];
			i++;
			len++;
		}
		stash = stash->next;
	}
	line[len] = '\0';
	return (line);
}

/*
	This function clean the stash from the line we just saved.
	It creates another chained list that keep the rest that was taken
	after the newline character and free every elements of the stash
	who were before the newline char.
	It used the function ft_free_stash who free the stash->content
	and the stash itself.
	return 0 if there is an error with a malloc
	return 1 if everything went well
*/
int	clean_used_stash(t_list_gnl	**stash)
{
	t_list_gnl	*last;
	t_list_gnl	*rest_stash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	rest_stash = malloc(sizeof(t_list_gnl));
	if (!rest_stash && !stash)
		return (0);
	rest_stash->next = NULL;
	last = ft_lstlast_gnl(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	rest_stash->content = malloc((ft_strlen_gnl(last->content) + 1 - i));
	if (!rest_stash->content)
		return (0);
	while (last->content[i])
		rest_stash->content[j++] = last->content[i++];
	rest_stash->content[j] = '\0';
	ft_free_stash(*stash);
	*stash = rest_stash;
	return (1);
}

/*
int	main()
{
	int		fd;
	char	*line;

	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("line : %s\n", line);
		free(line);
	}

}
*/
