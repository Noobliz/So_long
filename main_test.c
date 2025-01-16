/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/15 16:02:29 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	char		**map;
	t_img		img;
	t_data		data;
	t_element	element;

	data.img = &img;
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
	data.map = get_map();
	if (!map)
		return (0);
	if (!is_valid(map) || !valid_path(map, &element))
	{
		free_map(map);
		return (0);
	}
	data.element = &element;
	if (!img_init(&data))
		return (0);
	printf("collectible = %d\n", data.element->collectible);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);

	display_map(map, img, data);
	mlx_loop(data.mlx);
	return (0);
}
