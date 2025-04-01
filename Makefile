# Detect the operating system
UNAME_S := $(shell uname -s)

#COLOR
GREEN  		= \033[0;32m
CYAN   		= \033[0;36m
BLUE   		= \033[0;34m
DEFAULT  	= \033[0m
MAGENTA 	= \033[0;35m
RED    		= \033[0;31m
YELLOW 		= \033[0;33m

NAME 	= so_long
CC 		= gcc
CFLAGS 	= -Iinclude
RM 		= rm -rf

#mlx
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR		= mlx_linux
	MLX_LIB		= $(MLX_DIR)/libmlx.a
	MLX_INC 	= -I $(MLX_DIR)
	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	CFLAGS		+= -I$(MLX_DIR) -O3
	OS			= LINUX
else
	MLX_DIR		= mlx_mac
	MLX_LIB		= $(MLX_DIR)/libmlx.a
	MLX_INC 	= -I $(MLX_DIR)
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS		+= -I$(MLX_DIR)
	OS			= MAC
endif

#so_long
VPATH		= 	src:src/map_management:src/errors:get_next_line:src/player:src/background:src/fps:src/collision:src/delay:src/foe:src/animations:src/sprites:src/HUD:src/other:src/loop_and_end_game:src/trap:include
SO_LONG_INC	= so_long.h
SO_LONG_SRC	= $(addsuffix .c, 	main						\
								get_map						\
								get_map_utils_1				\
								get_map_utils_2				\
								map_parsing					\
								flood_fill					\
								add_collectibles			\
								init_collectibles_1			\
								init_collectibles_2			\
								customize_map_1				\
								customize_map_2				\
								customize_map_3				\
								customize_map_4				\
								add_foe_1					\
								add_foe_2					\
								add_trap_1					\
								add_trap_2					\
								map_error					\
								sprites						\
								player						\
								player_stats_and_items		\
								player_movement_1			\
								player_movement_2			\
								player_mana					\
								player_spells				\
								player_projectile_1			\
								player_projectile_2			\
								player_animation			\
								player_which_anim_state		\
								player_animation_run		\
								player_animation_idle		\
								player_animation_fly		\
								player_animation_meditating	\
								player_animation_falling	\
								player_animation_cast_spell	\
								foe_animation				\
								foe_animation_attack_01		\
								foe_animation_attack_02		\
								foe_1						\
								foe_2						\
								foe_attack					\
								foe_projectiles_1			\
								foe_projectiles_2			\
								trap						\
								draw_trap					\
								background					\
								background_trap				\
								exit						\
								collectibles				\
								collectibles_staff_1		\
								collectibles_staff_2		\
								collectibles_scroll_o_1		\
								collectibles_scroll_o_2		\
								collectibles_scroll_h_1		\
								collectibles_scroll_h_2		\
								collectibles_lights			\
								collision					\
								get_collision_background	\
								aabb						\
								aabb_foe					\
								aabb_trap					\
								aabb_collectibles			\
								delay						\
								delay_2						\
								fps							\
								hud							\
								check_map_foe_projectiles	\
								check_input					\
								tick						\
								end_game_1					\
								end_game_2					\
								end_game_3					\
								get_next_line				\
								get_next_line_utils			)

#printf
FT_PRINTF 			= libftprintf.a
FT_PRINTF_DIR 		= ft_printf
FT_PRINTF_FILE 		= $(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

#libft
LIBFT 				= libft.a
LIBFT_DIR 			= libft
LIBFT_FILE 			= $(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

all: $(MLX_LIB) $(NAME)

obj:
	@mkdir -p obj
SO_LONG_OBJ	= $(SO_LONG_SRC:%.c=obj/so_long/%.o)
LIB 		= $(FT_PRINTF_FILE) $(LIBFT_FILE)

$(SO_LONG_OBJ):	obj/so_long/%.o: %.c $(SO_LONG_INC)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_FILE):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_FILE):
	@echo "$(GREEN)+-------------------------------------+$(DEFAULT)"
	@echo "$(GREEN)|         Libft Compiling...          |   $(DEFAULT)"
	@echo "$(GREEN)+-------------------------------------+\n$(DEFAULT)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(NAME): $(LIB) $(SO_LONG_OBJ)
	@echo "$(GREEN)+-------------------------------------+$(DEFAULT)"
	@echo "$(GREEN)|         So_long Compiling...        |     $(DEFAULT)"
	@echo "$(GREEN)+-------------------------------------+\n$(DEFAULT)"
	@$(CC) $(CFLAGS) $(SO_LONG_OBJ) $(MLX_FLAGS) $(MLX_INC) $(LIB) -o $@

$(MLX_LIB):
	@echo "$(GREEN)+-------------------------------------+$(DEFAULT)"
	@echo "$(GREEN)|         MLX Compiling...            |  $(DEFAULT)"
	@echo "$(GREEN)+-------------------------------------+\n$(DEFAULT)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

clean_mlx:
	@$(MAKE) clean -C $(MLX_DIR)

clean_lib:
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean_lib:
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)

clean: clean_lib clean_mlx
	@echo "$(RED)Cleaning object files...$(DEFAULT)"
	@$(RM) obj


fclean:  clean fclean_lib
	@echo "$(RED)Cleaning executable...$(DEFAULT)"
	@$(RM) $(NAME)
	@sleep 1
	@clear

re:	fclean all

norminette:
	@echo "$(YELLOW)Exécution de norminette...$(DEFAULT)"
	@norminette src/* > norminette_output.txt || (echo "")
	@norminette include/* >> norminette_output.txt || (echo "")
	@norminette libft >> norminette_output.txt || (echo "")
	@error=0; \
	while IFS= read -r line; do \
		if ! echo "$$line" | grep -q 'OK!$$'; then \
			echo "$(RED)Erreur dans le fichier : $$line$(DEFAULT)"; \
			error=1; \
		fi; \
	done < norminette_output.txt || (echo "$(MAGENTA)Erreur lors de la vérification du résultat de norminette$(DEFAULT)"); \
	if [ $$error -eq 0 ]; then \
		echo "$(GREEN)Norminette OK!.$(DEFAULT)"; \
	fi
	@rm norminette_output.txt
	@echo " "

tester:
	@echo '#!/bin/bash' > map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# ANSI escape codes for green and red' >> map_error_tester.sh
	@echo 'GREEN='\''\033[0;32m'\''' >> map_error_tester.sh
	@echo 'RED='\''\033[0;31m'\''' >> map_error_tester.sh
	@echo 'BLUE='\''\033[0;34m'\''' >> map_error_tester.sh
	@echo 'NC='\''\033[0m'\'' # No Color' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Array of test cases' >> map_error_tester.sh
	@echo 'tests=("maps/maps_error_test/square.ber				" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/empty.ber				" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongextension			" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidpath/blockedcollect.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidpath/blockedexit.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidpath/blockedplayer.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidpath/cutinhalf.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongcollect/nocollect.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongexit/noexit.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongexit/twoexits.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongplayer/noplayer.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongplayer/twoplayer.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongwall/missingwall1.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongwall/missingwall2.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongwall/missingwall3.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongwall/missingwall4.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/wrongwall/noborder.ber		" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidchar/invalidchar1.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidchar/invalidchar2.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidchar/invalidchar3.ber	" ' >> map_error_tester.sh
	@echo '	"maps/maps_error_test/invalidchar/invalidchar4.ber	") ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Array of expected outputs ' >> map_error_tester.sh
	@echo 'expected_outputs=("Error - map must be a rectangle" ' >> map_error_tester.sh
	@echo '				"Error - map empty" ' >> map_error_tester.sh
	@echo '				"Error - map wrong extension" ' >> map_error_tester.sh
	@echo '				"Error - map accessibility errors" ' >> map_error_tester.sh
	@echo '				"Error - map accessibility errors" ' >> map_error_tester.sh
	@echo '				"Error - map accessibility errors" ' >> map_error_tester.sh
	@echo '				"Error - map accessibility errors" ' >> map_error_tester.sh
	@echo '				"Error - map must have at least one collectible" ' >> map_error_tester.sh
	@echo '				"Error - map must have one exit" ' >> map_error_tester.sh
	@echo '				"Error - map must have one exit" ' >> map_error_tester.sh
	@echo '				"Error - map must have one player" ' >> map_error_tester.sh
	@echo '				"Error - map must have one player" ' >> map_error_tester.sh
	@echo '				"Error - map must be surrounded by walls" ' >> map_error_tester.sh
	@echo '				"Error - map must be surrounded by walls" ' >> map_error_tester.sh
	@echo '				"Error - map must be surrounded by walls" ' >> map_error_tester.sh
	@echo '				"Error - map must be surrounded by walls" ' >> map_error_tester.sh
	@echo '				"Error - map must be surrounded by walls" ' >> map_error_tester.sh
	@echo '				"Error - map must only contain valid characters" ' >> map_error_tester.sh
	@echo '				"Error - map must only contain valid characters" ' >> map_error_tester.sh
	@echo '				"Error - map must only contain valid characters" ' >> map_error_tester.sh
	@echo '				"Error - map must only contain valid characters") ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Get the number of tests ' >> map_error_tester.sh
	@echo 'num_tests=$${#tests[@]} ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Index variable for the loop ' >> map_error_tester.sh
	@echo 'index=0 ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Loop over the tests ' >> map_error_tester.sh
	@echo 'while [ $$index -lt $$num_tests ] ' >> map_error_tester.sh
	@echo 'do ' >> map_error_tester.sh
	@echo '# Run the test and capture the output ' >> map_error_tester.sh
	@echo 'output=$$(./so_long $${tests[$$index]}) ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo 'if [ $$index -eq 0 ]; then ' >> map_error_tester.sh
	@echo '	echo -e "$${BLUE}\\nGeneral Map Error Tests$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo 'if [ $$index -eq 3 ]; then ' >> map_error_tester.sh
	@echo '	echo -e "$${BLUE}\\nInvalid Path Map Error Tests$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo 'if [ $$index -eq 7 ]; then ' >> map_error_tester.sh
	@echo '	echo -e "$${BLUE}\\nWrong Mandatory Map Error Tests$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo 'if [ $$index -eq 12 ]; then ' >> map_error_tester.sh
	@echo '	echo -e "$${BLUE}\\nWrong Wall Map Error Tests$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo 'if [ $$index -eq 17 ]; then ' >> map_error_tester.sh
	@echo '	echo -e "$${BLUE}\\nInvalid Char Map Error Tests$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Compare the output to the expected output ' >> map_error_tester.sh
	@echo 'if [ "$$output" == "$${expected_outputs[$$index]}" ]; then ' >> map_error_tester.sh
	@echo '   echo -e "$${NC}$${tests[$$index]} $${GREEN}passed$${NC}" ' >> map_error_tester.sh
	@echo 'else ' >> map_error_tester.sh
	@echo '    echo -e "$${NC}$${tests[$$index]} $${RED}failed$${NC}" ' >> map_error_tester.sh
	@echo 'fi ' >> map_error_tester.sh
	@echo '' >> map_error_tester.sh
	@echo '# Increment the index ' >> map_error_tester.sh
	@echo '((index++)) ' >> map_error_tester.sh
	@echo 'done ' >> map_error_tester.sh
	@chmod +x map_error_tester.sh
	@./map_error_tester.sh
	@$(RM) map_error_tester.sh


.PHONY:	all clean fclean re
