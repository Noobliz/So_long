/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/14 15:49:48 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	main(void)
// {
// 	char **map;
// 	map = get_map();
// 	if (!is_valid(map))
// 	{
// 		free_map(map);
// 		return (0);
// 	}
// 	if (valid_path(map))
// 		printf("Valid path found \n");
// 	else
// 		printf("Error\nNo valid path found\n");
// 	free_map(map);
// 	return (0);
// }
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	char	**map;
	t_img	img;
	t_data	data;

	data.mlx = 0;
	data.window = 0;
	img.img_wall = 0;
	img.img_lantern = 0;
	img.img_floor = 0;
	img.img_char = 0;
	img.img_coll = 0;
	img.img_exit = 0;
	img.img_width = 0;
	img.img_height = 0;
	map = get_map();
	if (!is_valid(map))
	{
		free_map(map);
		return (0);
	}
	if (valid_path(map))
		printf("Valid path found \n");
	else
		printf("Error\nNo valid path found\n");
	if (!img_init(&img, &data))
		return (0);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	display_map(map, img, data);
	mlx_loop(data.mlx);
	// mlx_destroy_image(data.mlx, img.img_char);
	// mlx_destroy_image(data.mlx, img.img_coll);
	// mlx_destroy_image(data.mlx, img.img_exit);
	// mlx_destroy_image(data.mlx, img.img_floor);
	// mlx_destroy_image(data.mlx, img.img_wall);
	// mlx_destroy_image(data.mlx, img.img_lantern);
	// mlx_destroy_display(data.mlx);
	// free(data.mlx);
	// // exit(0);
	return (0);
	// image window display
}
