/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:47 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/15 13:05:08 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->window);
	return (0);
}
void	destroy_images(t_img *img, void *mlx)
{
	if (img->img_wall)
		mlx_destroy_image(mlx, img->img_wall);
	if (img->img_floor)
		mlx_destroy_image(mlx, img->img_floor);
	if (img->img_lantern)
		mlx_destroy_image(mlx, img->img_lantern);
	if (img->img_char)
		mlx_destroy_image(mlx, img->img_char);
	if (img->img_coll)
		mlx_destroy_image(mlx, img->img_coll);
	if (img->img_exit)
		mlx_destroy_image(mlx, img->img_exit);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		destroy_images(data->img, data->mlx);
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		// free_map(map);
		exit(0);
	}
	return (0);
}
