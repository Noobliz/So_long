/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:47 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/17 15:24:13 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	end_game(t_data *data)
{
	destroy_images(data->img, data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(0);
}

void	update_map(t_data *data, int new_y, int new_x)
{
	if (data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] == 'C')
		{
			data->map[new_y][new_x] = '0';
			data->element->collectible--;
		}
		if (data->map[new_y][new_x] != 'E')
		{
			data->map[data->element->player_y][data->element->player_x] = '0';
			data->map[new_y][new_x] = 'P';
			data->element->player_x = new_x;
			data->element->player_y = new_y;
		}
		ft_printf("Moves: %d\n", data->element->move_count);
		data->element->move_count++;
		display_map(data->map, *(data->img), *data);
		if (data->map[new_y][new_x] == 'E' && data->element->collectible == 0)
		{
			end_game(data);
		}
	}
}
int	handle_keypress(int keysym, t_data *data)
{
	int	new_x;
	int	new_y;

	if (keysym == XK_Escape)
		end_game(data);
	new_x = data->element->player_x;
	new_y = data->element->player_y;
	if (keysym == XK_Up || keysym == XK_w)
		new_y--;
	else if (keysym == XK_Down || keysym == XK_s)
		new_y++;
	else if (keysym == XK_Left || keysym == XK_a)
		new_x--;
	else if (keysym == XK_Right || keysym == XK_d)
		new_x++;
	update_map(data, new_y, new_x);
	return (0);
}
