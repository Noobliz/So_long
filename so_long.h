/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:34:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/17 15:27:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "LIBFT/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int			player;
	int			collectible;
	int			exit;
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;
	int			move_count;
}				t_element;

typedef struct s_img
{
	void		*img_wall;
	void		*img_lantern;
	void		*img_floor;
	void		*img_char;
	void		*img_coll;
	void		*img_exit;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	t_img		*img;
	t_element	*element;
}				t_data;

//---------------------------UTILS
char			**get_map(void);
void			free_map(char **map);
int				map_size(void);
int				map_width(char **map);
int				map_height(char **map);
void			init_struct(t_element *element);
//--------------------------------------------MAP Parsing
int				is_rectangular(char **map);
int				is_surrounded_by_walls(char **map);
int				has_all_elements(char **map);
int				is_valid(char **map);
//---------------------------------------------PATH Valid
void			find_player_count_c(char **map, t_element *element);
int				valid_path(char **map, t_element *element);
//-------------------------------------------------------------MAP display
void			display_map(char **map, t_img img, t_data data);
void				img_init(t_data *data);
//-------------------------------------------------------------Window related

int				handle_keypress(int keysym, t_data *data);
void			destroy_images(t_img *img, void *mlx);
void			end_game(t_data *data);

#endif