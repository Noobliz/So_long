/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:50:43 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/14 14:13:47 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

int	img_init(t_img *img, t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 800, 600, "So Long");
	img->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&img->img_width, &img->img_height);
	img->img_lantern = mlx_xpm_file_to_image(data->mlx, "assets/lantern.xpm",
			&img->img_width, &img->img_height);
	img->img_floor = mlx_xpm_file_to_image(data->mlx, "assets/ground2.xpm",
			&img->img_width, &img->img_height);
	img->img_char = mlx_xpm_file_to_image(data->mlx, "assets/hoodi.xpm",
			&img->img_width, &img->img_height);
	img->img_coll = mlx_xpm_file_to_image(data->mlx, "assets/potion.xpm",
			&img->img_width, &img->img_height);
	img->img_exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&img->img_width, &img->img_height);
	if (!img->img_wall || !img->img_floor || !img->img_lantern || !img->img_char
		|| !img->img_coll || !img->img_exit)
	{
		printf("Error\nNo image charged\n");
		return (0);
	}
	return (1);
}

void	display_walls(char c, int x, int y, t_img img, t_data data)
{
	if (c == '1' && y % 2 == 0 && x % 2 == 0)
		mlx_put_image_to_window(data.mlx, data.window, img.img_lantern, x
			* img.img_width, y * img.img_height);
	else
		mlx_put_image_to_window(data.mlx, data.window, img.img_wall, x
			* img.img_width, y * img.img_height);
}
void	display_P_C_E(char c, int x, int y, t_img img, t_data data)
{
	if (c == '0')
		mlx_put_image_to_window(data.mlx, data.window, img.img_floor, x
			* img.img_width, y * img.img_height);
	else if (c == 'P')
		mlx_put_image_to_window(data.mlx, data.window, img.img_char, x
			* img.img_width, y * img.img_height);
	else if (c == 'C')
		mlx_put_image_to_window(data.mlx, data.window, img.img_coll, x
			* img.img_width, y * img.img_height);
	else if (c == 'E')
		mlx_put_image_to_window(data.mlx, data.window, img.img_exit, x
			* img.img_width, y * img.img_height);
}

void	display_map(char **map, t_img img, t_data data)
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
				display_walls(map[y][x], x, y, img, data);
			else
				display_P_C_E(map[y][x], x, y, img, data);
			x++;
		}
		y++;
	}
	mlx_loop(data.mlx);
}
