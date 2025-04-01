# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:43:52 by thenguye          #+#    #+#              #
#    Updated: 2024/01/11 18:59:01 by thenguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN  		= \033[0;32m
CYAN   		= \033[0;36m
BLUE   		= \033[0;34m
DEFAULT  	= \033[0m
MAGENTA 	= \033[0;35m
RED    		= \033[0;31m
YELLOW 		= \033[0;33m

NAME 		= libftprintf.a
CC 			= gcc
INC_DIR 	= include
CFLAGS 		= -Wall -Werror -Wextra -I$(INC_DIR)
RM			= rm -rf

SRC = $(addsuffix .c,	ft_printf			\
						ft_putchar_pf		\
						ft_putstr_pf		\
						ft_putnbr_base_ten	\
						ft_putnbru_base_ten	\
						ft_putnbr_hex		\
						ft_putpointer)

OBJS = $(addprefix obj/, $(SRC:.c=.o))

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

norminette:
	@echo "$(CYAN)\nCheck norminette: $(DEFAULT)$(NAME)\n"
	@echo "$(CYAN)\n\tCheckForbiddenSourceHeader $(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader
	@echo "$(CYAN)\n\tCheckDefine $(DEFAULT)"
	@norminette -R CheckDefine
	@echo "$(GREEN)\n+---------------------------------------------------------+ $(DEFAULT)"
	@echo "$(GREEN)|$(BLUE)   ✔✔✔ $(YELLOW)Norminette $(NAME) done and validated$(BLUE) ✔✔✔   $(GREEN)| $(DEFAULT)"
	@echo "$(GREEN)+---------------------------------------------------------+ $(DEFAULT)\n"

obj:
	@mkdir -p obj

obj/%.o: %.c | obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) obj

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
