/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/17 15:28:05 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_img		img;
	t_data		data;
	t_element	element;

	init_struct(&element);
	data.img = &img;
	data.mlx = 0;
	data.window = 0;
	data.map = get_map();
	if (!data.map)
		return (0);
	if (!is_valid(data.map) || !valid_path(data.map, &element))
	{
		free_map(data.map);
		return (0);
	}
	img_init(&data);
	data.element = &element;
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	display_map(data.map, img, data);
	mlx_loop(data.mlx);
	return (0);
}
