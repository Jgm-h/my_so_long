#ifndef SO_LONG_H
# define SO_LONG_H

// LIBRAIRIE
# include	"../Libft/includes/libft.h"
# include	"../Libft/includes/get_next_line.h"
# include	"../Libft/includes/ft_printf.h"
# include	"../mlx/mlx.h"
# include	<stdio.h>
# include	<fcntl.h>

// KEYS
# define KEY_UP 			13
# define KEY_RIGHT			2
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_CLOSE_WINDOW	53

// PATH
# define SIZE				32
# define GROUND				"./sprites/ground.xpm"
# define WALL				"./sprites/wall.xpm"
# define COLLECTIBLE		"./sprites/collectible.xpm"
# define CHARACTER			"./sprites/character.xpm"
# define DOOR				"./sprites/door.xpm"

// EVENTS
# define KEY_UP 			13
# define KEY_RIGHT			2
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_CLOSE_WINDOW 	53

// ERRORS
# define MEMORY				1
# define NAME				2
# define MAP				3
# define PATH				4

//enum {
//	MEMORYa = 5,
//};

// STRUCTS
typedef struct s_sprite
{
	void	*sprite;
	char	*path;
	int		width;
	int		length;
}t_sprite;

typedef struct s_long
{
	int			ppy;
	int			ppx;

	int			map_width;
	int			map_height;
	int			nbr_collectible;
	int			nbr_c_check;
	int			nbr_player;
	int			nbr_door;
	int			nbr_d_check;
	int			nbr_steps;

	void		*mlx_ptr;
	void		*win_ptr;

	char		*first_map;
	char		**map;

	t_sprite	*ground;
	t_sprite	*wall;
	t_sprite	*collectible;
	t_sprite	*character;
	t_sprite	*door;
}t_long;

// init_game
void	init_game(t_long *game);
void	init_sprites_path(t_long *game);
void	init_sprites_image(t_long *game);
void	init_values(t_long *game);

// init_map
void	init_map(t_long *game, char **argv);
char	*read_fd(char *map, t_long *game);
char	**fill_map(char *line, t_long *game);
int		elements_per_line(char *line);
int		number_of_lines(char *line);

// check_map
void	check_map(t_long *game);
void	check_elements_length(t_long *game, int i, int j, int length);
void	check_elements(t_long *game, int i, int j);
void	check_walls(t_long *game);
int		check_path(int ppy, int ppx, char **map, t_long *game);
char	**double_map(t_long *game);

// print_map
void	init_window(t_long *game);
void	print_map(t_long *game);
void	count_collectibles(t_long *game);
void	img_to_window(char c, t_long *game, int i, int j);

// movement
int		hook(int key, t_long *game);
void	move_left(t_long *game);
void	move_right(t_long *game);
void	move_up(t_long *game);
void	move_down(t_long *game);

// destroy
int		destroy_game(t_long *game);
void	free_map(char **map);
void	error_management(t_long *game, int error);

#endif