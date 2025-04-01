# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:30:08 by thenguye          #+#    #+#              #
#    Updated: 2024/01/30 11:56:01 by thenguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(addsuffix .c, 	ft_isalpha 		\
						ft_isdigit 		\
						ft_isalnum 		\
						ft_isascii 		\
						ft_isprint 		\
						ft_strlen		\
						ft_memset		\
						ft_bzero		\
						ft_memcpy		\
						ft_memmove		\
						ft_strlcpy		\
						ft_strlcat		\
						ft_toupper		\
						ft_tolower		\
						ft_strchr		\
						ft_strrchr		\
						ft_strncmp		\
						ft_memchr		\
						ft_memcmp		\
						ft_strnstr		\
						ft_atoi			\
						ft_calloc		\
						ft_strdup		\
						ft_substr		\
						ft_strjoin		\
						ft_strtrim		\
						ft_split		\
						ft_itoa			\
						ft_strmapi		\
						ft_striteri		\
						ft_putchar_fd	\
						ft_putstr_fd	\
						ft_putendl_fd	\
						ft_putnbr_fd)

OBJS = $(addprefix obj/, $(SRC:.c=.o))

SRC_BONUS = $(addsuffix .c,	ft_lstnew		\
							ft_lstadd_front	\
							ft_lstsize		\
							ft_lstlast		\
							ft_lstadd_back	)

OBJS_BONUS  = $(addprefix obj_bonus/, $(SRC_BONUS:.c=.o))

OBJS_ALL = $(OBJS) $(OBJS_BONUS)

CC = gcc

INC_DIR = include

CFLAGS += -I$(INC_DIR)

CCFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

obj:
	mkdir -p obj
	
obj_bonus:
	mkdir -p obj_bonus

$(NAME): $(OBJS_ALL)
	ar rcs $(NAME) $(OBJS_ALL)

obj/%.o: %.c | obj
	@$(CC) $(CFLAGS) -o $@ -c $<

obj_bonus/%.o: %.c | obj_bonus
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf obj
	rm -rf obj_bonus

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
	