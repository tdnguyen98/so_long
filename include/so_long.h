/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenguye <thenguye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:57:39 by thenguye          #+#    #+#             */
/*   Updated: 2025/04/06 20:35:16 by thenguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <sys/time.h>

# define TSPX 256
# define RES_IMACX 2560
# define RES_IMACY 1395
# define RES_MACM1X 1500
# define RES_MACM1Y 900

# define SPRITES_PLAYER 46
# define SPRITES_FOE 25
# define SPRITES_COLLECT 6
# define SPRITES_EXIT 10
# define SPRITES_BACKGROUND 28
# define SPRITES_HUD 63

# ifdef __APPLE__
#  define ESC_KEY 53
#  define W_KEY 13
#  define S_KEY 1
#  define A_KEY 0
#  define D_KEY 2
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define SKILL_1 83
#  define SKILL_2 84
#  define SKILL_1_NUMPAD 18
#  define SKILL_2_NUMPAD 19
# else
#  define ESC_KEY 65307
#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define SKILL_1 49
#  define SKILL_2 50
#  define SKILL_1_NUMPAD 65457
#  define SKILL_2_NUMPAD 65458
# endif

/*
* collision_type[0] = blocking
* collision_type[1] = exit
* collision_type[2] = collectible
* collision_type[3] = blocking and damaging
*/
typedef struct s_collision
{
	int					top_left[2];
	int					top_right[2];
	int					bottom_left[2];
	int					bottom_right[2];
	int					collision_type[4];
	struct s_collision	*next;
}	t_collision;

typedef struct s_collect
{
	int					light;
	int					light_offset;
	int					light_pos[2];
	int					pos_top_left[2];
	int					pos_top_right[2];
	int					pos_bottom_left[2];
	int					pos_bottom_right[2];
	struct s_collect	*next;
}	t_collect;

typedef struct s_staff
{
	int	pos[2];
	int	pos_base[2];
	int	pos_top_left[2];
	int	pos_top_right[2];
	int	pos_bottom_left[2];
	int	pos_bottom_right[2];
	int	staff;
	int	staff_offset;
}	t_staff;

typedef struct s_scroll
{
	int	orb;
	int	orb_offset;
	int	o_pos_base[2];
	int	orb_pos[2];
	int	o_pos_top_left[2];
	int	o_pos_top_right[2];
	int	o_pos_bottom_left[2];
	int	o_pos_bottom_right[2];
	int	heal;
	int	heal_offset;
	int	h_pos_base[2];
	int	heal_pos[2];
	int	h_pos_top_left[2];
	int	h_pos_top_right[2];
	int	h_pos_bottom_left[2];
	int	h_pos_bottom_right[2];
}	t_scroll;

typedef struct s_exit
{
	int	pos[2];
	int	is_open;
	int	is_far;
	int	pos_top_left[2];
	int	pos_top_right[2];
	int	pos_bottom_left[2];
	int	pos_bottom_right[2];
}	t_exit;

typedef struct s_projectile
{
	int	pos[2];
	int	pos_top_left[2];
	int	pos_top_right[2];
	int	pos_bottom_left[2];
	int	pos_bottom_right[2];
	int	direction;
	int	nbr;
	int	is_dead;
}	t_proj;

typedef struct s_foe
{
	int				pos[2];
	int				pos_top_left[2];
	int				pos_top_right[2];
	int				pos_bottom_left[2];
	int				pos_bottom_right[2];
	int				move[2];
	int				is_attacking;
	int				direction;
	int				is_dead;
	int				anim_delay;
	int				attack_delay;
	int				cooldown;
	t_proj			*projectile1;
	t_proj			*projectile2;
	t_proj			*projectile3;
	struct s_foe	*next;
}	t_foe;

typedef struct s_trap
{
	int				pos[2];
	int				pos_top_left[2];
	int				pos_top_right[2];
	int				pos_bottom_left[2];
	int				pos_bottom_right[2];
	int				delay;
	int				is_triggered;
	int				dir;
	struct s_trap	*next;
}	t_trap;

/*
* block a to b are for all different position of wall
* collect, staff and scrolls, are the three differents
*kind of collectibles in the game.
*/
typedef struct s_map
{
	char		**map;
	size_t		width;
	size_t		height;
	int			player;
	int			player_pos[2];
	int			collectible;
	t_list		*collect_pos;
	t_exit		*exit;
	int			block_a;
	int			block_c;
	int			block_d;
	int			block_e;
	int			block_f;
	int			block_g;
	int			block_h;
	int			block_i;
	int			block_j;
	int			block_k;
	int			block_l;
	int			block_m;
	int			block_n;
	int			block_o;
	int			block_p;
	int			exit_count;
	t_collect	*collect;
	t_staff		*staff;
	t_scroll	*scroll;
	int			error;
	int			is_flooded;
	t_foe		*foe;
	t_trap		*trap;
}	t_map;

/*
*
* pos[0] = x axis
* pos[1] = y axis
* offset[0] = left x axis
* offset[1] = right x axis
* offset[2] = top y axis
* offset[3] = bottom y axis
* move[0] = left
* move[1] = right
* move[2] = up
* move[3] = down
* direction : 1 = left, 0 = right
* damage_taken_delay[0] = damage taken flag
* damage_taken_delay[1] = delay
*/
typedef struct s_player
{
	int		life_points;
	int		mana_points;
	int		damage_taken_delay[2];
	int		anim_delay;
	int		anim_delay_fall[2];
	int		cast_spell_anim[2];
	int		pos[2];
	int		pos_top_left[2];
	int		pos_top_right[2];
	int		pos_bottom_left[2];
	int		pos_bottom_right[2];
	int		move[4];
	int		spells[2];
	int		spell_heal_timer[3];
	t_proj	*projectile1;
	int		is_on_ground;
	int		is_running;
	int		is_flying;
	int		is_falling;
	int		no_mana_fall;
	int		no_mana_fall_dmg;
	int		levitating_move;
	int		anim_staff_offset;
	int		got_items[3];
	int		direction;
}	t_player;

typedef struct s_sprites
{
	int		img_width;
	int		img_height;
	void	*player[SPRITES_PLAYER];
	void	*foe[SPRITES_FOE];
	void	*collectible[SPRITES_COLLECT];
	void	*exit[SPRITES_EXIT];
	void	*background[SPRITES_BACKGROUND];
	void	*hud[SPRITES_HUD];
}	t_sprites;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_sprites	sprites;
	t_player	*player;
	t_collision	*collision;
	long long	lm;
	int			fps;
	int			steps;
	int			ending[3];
}	t_data;

/*get map*/
t_map			get_map(t_map *map, char *argv[]);
void			init_map_struct(t_map *map);
void			init_map_bloc(t_map *map);
void			init_data_ending(t_data *data);
void			check_map_extension(t_map *map, char *argv[]);
void			get_height(t_map *map, char *argv[]);
void			fill_map(t_map *map, char *argv[]);
void			check_map_proportions(t_map *map);
void			map_parsing(t_map *map, size_t height);
void			get_map_utils(t_map *map, int row, int col);
void			check_map_mandatory(t_map *map);
void			is_char_valid(t_map *map, char c);
void			find_char_player(t_map *map);
void			flood_fill(t_map *map, int row, int col);
int				is_next_char_ok(char c);
void			map_error(t_map *map, int error);
void			free_map(t_map *map);
void			free_stash(t_list *pos);
void			define_collectibles(t_map *map);
void			create_staff(t_map *map, int x, int y);
void			create_scroll(t_map *map, int x, int y, char c);
void			init_scroll_orb(t_map *map, int x, int y);
void			init_scroll_heal(t_map *map, int x, int y);
void			create_collectible(t_map *map, int x, int y);
void			ft_lstadd_back_collect(t_collect **lst, t_collect *new);
t_collect		*ft_lstlast_collect(t_collect *lst);
int				*put_pos_in_tab(t_map *map);
void			change_map_borders(t_map *map);
void			change_wall_in_map(t_map *map);
void			add_randomness(t_map *map);
void			are_exit_scroll_staff_on_ground(t_map *map);
int				is_on_ground(t_map *map, int y, int x);

char			create_interior_map(t_map *map, int row, int col);
char			create_interior_map_2(t_map *map, int row, int col, char **str);
int				check_char(char c, const char *str);
int				is_block_a(t_map *map, int y, int x, char **str);
int				is_block_b(t_map *map, int y, int x, char **str);
int				is_block_c(t_map *map, int y, int x, char **str);
int				is_block_d(t_map *map, int y, int x, char **str);
int				is_block_e(t_map *map, int y, int x, char **str);
int				is_block_f(t_map *map, int y, int x, char **str);
int				is_block_g(t_map *map, int y, int x, char **str);
int				is_block_h(t_map *map, int y, int x, char **str);
int				is_block_i(t_map *map, int y, int x, char **str);
int				is_block_j(t_map *map, int y, int x, char **str);
int				is_block_k(t_map *map, int y, int x, char **str);
int				is_block_l(t_map *map, int y, int x, char **str);
int				is_block_m(t_map *map, int y, int x, char **str);
int				is_block_n(t_map *map, int y, int x, char **str);
int				is_block_o(t_map *map, int y, int x, char **str);
int				is_block_p(t_map *map, int y, int x, char **str);

void			draw_collectibles(t_data *data);
void			draw_staff(t_data *data);
void			draw_tile_staff(t_data *data, int x, int y);
void			draw_tile_base_staff(t_data *data, int x, int y);
void			move_staff(t_data *data);
void			new_collision_staff(t_data *data);
int				check_collision_staff(t_data *data);
int				aabb_staff(t_data *data, int x, int y);
void			draw_scroll_orb(t_data *data);
void			draw_tile_scroll_orb(t_data *data, int x, int y);
void			draw_tile_base_scroll_orb(t_data *data, int x, int y);
void			move_scroll_orb(t_data *data);
void			new_collision_scroll_orb(t_data *data);
int				check_collision_scroll_orb(t_data *data);
int				aabb_scroll_orb(t_data *data, int x, int y);
void			draw_scroll_heal(t_data *data);
void			draw_tile_scroll_heal(t_data *data, int x, int y);
void			draw_tile_base_scroll_heal(t_data *data, int x, int y);
void			move_scroll_heal(t_data *data);
void			new_collision_scroll_heal(t_data *data);
int				check_collision_scroll_heal(t_data *data);
int				aabb_scroll_heal(t_data *data, int x, int y);
void			draw_light(t_data *data);
void			draw_tile_light(t_data *data, int x, int y, t_collect *light);
void			move_light(t_collect *light);
void			new_collision_light(t_collect *light);
int				check_collision_light(t_data *data, t_collect *light);
int				aabb_light(t_data *data, int x, int y, t_collect *light);

void			init_sprites(t_data *data);
int				draw_player(t_data *data);
void			animation(t_data *data);
int				is_player_meditating(t_data *data);
int				is_player_running(t_data *data);
int				is_player_flying(t_data *data);
int				is_player_idleling(t_data *data);
int				is_player_falling(t_data *data);
void			animation_run(t_data *data);
void			animation_run_right(t_data *data);
void			animation_run_left(t_data *data);
void			animation_fly(t_data *data);
void			animation_fly_right(t_data *data);
void			animation_fly_left(t_data *data);
void			animation_idle(t_data *data);
void			animation_mirror(t_data *data);
void			animation_meditating(t_data *data);
void			animation_fall(t_data *data);
void			animation_cast_spell(t_data *data);
void			init_player(t_data *data);
void			init_player_2(t_data *data);
void			init_player_inventory(t_data *data);
void			init_player_collision(t_data *data);
void			draw_background(t_data *data);
void			get_player_pos(t_data *data);
int				tick(t_data *data);
void			draw(t_data *data);
void			draw_tile_backround(t_data *data, int x, int y, char c);
void			set_tile_trap_collision(t_data *data, int x, int y, char c);
int				get_background_index(char c);
int				get_background_index_2(char c);
void			mana_management(t_data *data);
void			mana_regen(t_data *data);
void			mana_cost_fly(t_data *data);
void			player_spells(t_data *data);
void			spell_1_orb(t_data *data);
void			create_orb(t_data *data);
void			spell_2_heal(t_data *data);
void			health_regen(t_data *data);
void			draw_player_projectile(t_data *data);
void			player_projectiles(t_data *data, t_proj *proj);
void			move_proj_player(t_data *data, t_proj *projectile, int dir);
void			draw_proj_player(t_data *data, int x, int y, t_proj *proj);
void			projectile_player_new_collision(t_proj *projectile);
void			proj_player_new_collision_offset(t_proj *proj, int x, int y);
void			move_projectile_player_right(t_data *data, t_proj *proj);
void			move_projectile_player_left(t_data *data, t_proj *proj);
void			projectile_player_hit_foe(t_data *data, t_proj *proj);
void			free_player(t_player *to_free);

void			set_move(t_data *data, int keysym);
void			reset_move(t_data *data, int keysym);
void			movement(t_data *data);
int				movement_1(t_data *data);
void			movement_2(t_data *data);
void			movement_3(t_data *data);
void			movement_4(t_data *data);
void			direction(t_player *player);

void			set_collision(t_data *data, int x, int y, int type);
void			set_collision_trap_right(t_data *data, int x, int y, int type);
void			set_collision_trap_up(t_data *data, int x, int y, int type);
void			set_collision_trap_left(t_data *data, int x, int y, int type);
void			ft_lstadd_back_collision(t_collision **lst, t_collision *new);
t_collision		*ft_lstlast_collision(t_collision *lst);
int				check_collision(t_data *data, int dir);
int				aabb(t_data *data, t_collision *collision, char dir, int i);
int				aabb_down(t_data *data, t_collision *collision, int i);
int				aabb_up(t_data *data, t_collision *collision, int i);
int				aabb_left(t_data *data, t_collision *collision, int i);
int				aabb_right(t_data *data, t_collision *collision, int i);

void			fps(t_data *data);
long long		millitimestamp(void);
void			show_fps(t_data *data);

int				close_game(t_data *data);
void			display_ending(t_data *data);
void			free_collision(t_collision *no_zone);
void			check_player_stats_and_inventory(t_data *data);

void			delay(t_data *data);
void			delay_damage_taken(t_data *data);
void			delay_anim_fall(t_data *data);
void			delay_foe_attack_02(t_foe *foe);
void			delay_cooldown_heal(t_data *data);
void			delay_trap(t_data *data);
void			delay_cast_spell_anim(t_data *data);

int				probability(int prob);
void			add_enemies(t_map *map);
void			get_foe(t_map *map, int col, int row);
void			ft_lstadd_back_foe(t_foe **lst, t_foe *new);
t_foe			*ft_lstlast_foe(t_foe *lst);
void			free_foe(t_foe *to_free);
void			free_projectiles(t_foe *foe);
void			draw_foe(t_data *data);
t_foe			*is_foe_attacking_01(t_foe *foe, t_data *data);
t_foe			*is_foe_attacking_02(t_foe *foe, t_data *data);
void			animation_foe(t_data *data, int x, int y, t_foe *foe);
void			foe_walk_right(t_data *data, int x, int y, t_foe *foe);
void			foe_walk_left(t_data *data, int x, int y, t_foe *foe);
void			move_foe(t_data *data, t_foe *foe);
void			move_foe_right(t_data *data, t_foe *foe);
void			move_foe_left(t_data *data, t_foe *foe);
void			new_collision_foe(t_foe *foe);
void			dead_collision_foe(t_foe *foe);
void			foe_attack_01(t_data *data, int x, int y, t_foe *foe);
void			foe_attack_01_right(t_data *data, int x, int y, t_foe *foe);
void			foe_attack_01_left(t_data *data, int x, int y, t_foe *foe);
void			foe_attack_02(t_data *data, int x, int y, t_foe *foe);
void			foe_attack_02_right(t_data *data, int x, int y, t_foe *foe);
void			foe_attack_02_left(t_data *data, int x, int y, t_foe *foe);
t_proj			*new_projectile(int x, int y, int direction);
void			projectile_collision(t_proj *projectile, int x, int y, int dir);
void			get_foe_projectiles(t_data *data, t_foe *foe);
t_proj			*kill_foe_projectile(t_proj *proj);
void			foe_projectiles(t_data *data, t_proj *proj);
void			move_projectile(t_data *data, t_proj *projectile, int dir);
void			move_projectile_right(t_data *data, t_proj *proj);
void			move_projectile_left(t_data *data, t_proj *proj);
void			draw_projectile(t_data *data, int x, int y, t_proj *projectile);
void			projectile_new_collision(t_proj *projectile);
void			projectile_new_collision_offset(t_proj *proj, int x, int y);

int				aabb_foe(t_data *data, t_foe *collision, int x, int y);
int				aabb_foe_distance(t_data *data, t_foe *collision, int x, int y);
int				aabb_foe_proj(t_data *data, t_proj *collision, int x, int y);
int				aabb_player_projectile(t_foe *foe, t_proj *collision);
int				aabb_trap(t_data *data, t_trap *collision, int x, int y);

void			get_trap(t_map *map, int col, int row, int dir);
t_trap			*get_trap_pos_collision(t_trap *tmp, int col, int row, int dir);
t_trap			*trap_right_trigger_collision(t_trap *tmp, int col, int row);
t_trap			*trap_up_trigger_collision(t_trap *tmp, int col, int row);
t_trap			*trap_left_trigger_collision(t_trap *tmp, int col, int row);
void			ft_lstadd_back_trap(t_trap **lst, t_trap *new);
t_trap			*ft_lstlast_trap(t_trap *lst);
void			trap(t_data *data);
void			draw_tile_trap(t_data *data, int x, int y, int dir);
void			free_trap(t_trap *to_free);
void			free_staff(t_staff *to_free);
void			free_scroll(t_scroll *to_free);
void			free_collect(t_collect *to_free);
void			free_exit(t_exit *to_free);

void			draw_exit(t_data *data);
void			draw_tile_exit(t_data *data, int x, int y);
int				aabb_exit(t_data *data, int x, int y);

void			draw_hud(t_data *data);
void			draw_hud_life(t_data *data);
void			draw_hud_mana(t_data *data);
void			draw_hud_steps(t_data *data);
int				encode_rgb(int r, int g, int b);

int				key_pressed(int keysym, t_data *data);
int				key_released(int keysym, t_data *data);
void			event(t_data *data);

int				check_map_foe_projectiles(char c);

#endif
