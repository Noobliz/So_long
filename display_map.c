/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:50:43 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/21 12:11:12 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_data *data)
{
	int	y;
	int	x;
	int	height;
	int	width;

	y = map_height(data->map);
	x = map_width(data->map);
	height = y * 32;
	width = x * 32;
	if (width > 1920 || height > 1080)
	{
		free_map(data->map);
		ft_printf("Map is bigger than screen\n");
		exit(0);
	}
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, width, height, "So Long");
}

void	img_init(t_data *data)
{
	open_window(data);
	data->img->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img->img_width, &data->img->img_height);
	data->img->img_floor = mlx_xpm_file_to_image(data->mlx,
			"assets/ground2.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_lantern = mlx_xpm_file_to_image(data->mlx,
			"assets/lantern.xpm", &data->img->img_width,
			&data->img->img_height);
	data->img->img_char = mlx_xpm_file_to_image(data->mlx, "assets/hoodi.xpm",
			&data->img->img_width, &data->img->img_height);
	data->img->img_coll = mlx_xpm_file_to_image(data->mlx, "assets/potion.xpm",
			&data->img->img_width, &data->img->img_height);
	data->img->img_exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img->img_width, &data->img->img_height);
	if (!data->img->img_wall || !data->img->img_floor || !data->img->img_lantern
		|| !data->img->img_char || !data->img->img_coll || !data->img->img_exit)
	{
		end_game(data);
		ft_printf("Error\nNo image initialized\n");
		exit(0);
	}
}

void	display_walls(char c, int x, int y, t_data data)
{
	if (c == '1' && y % 2 == 0 && x % 2 == 0)
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_lantern, x
			* data.img->img_width, y * data.img->img_height);
	else
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_wall, x
			* data.img->img_width, y * data.img->img_height);
}

void	display_p_c_e(char c, int x, int y, t_data data)
{
	if (c == '0')
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_floor, x
			* data.img->img_width, y * data.img->img_height);
	else if (c == 'P')
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_char, x
			* data.img->img_width, y * data.img->img_height);
	else if (c == 'C')
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_coll, x
			* data.img->img_width, y * data.img->img_height);
	else if (c == 'E')
		mlx_put_image_to_window(data.mlx, data.window, data.img->img_exit, x
			* data.img->img_width, y * data.img->img_height);
}

void	display_map(char **map, t_data data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				display_walls(map[y][x], x, y, data);
			else
				display_p_c_e(map[y][x], x, y, data);
			x++;
		}
		y++;
	}
}
