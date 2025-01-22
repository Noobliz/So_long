/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:08:29 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/20 16:19:12 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

void	end_game(t_data *data)
{
	destroy_images(data->img, data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(0);
}

int	handle_close(t_data *data)
{
	end_game(data);
	return (0);
}
