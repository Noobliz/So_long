/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:47 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/21 13:30:15 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_printf("Moves: %d\n", data->element->move_count);
			data->element->move_count++;
		}
		display_map(data->map, *data);
		if (data->map[new_y][new_x] == 'E' && data->element->collectible == 0)
		{
			ft_printf("Moves: %d\n", data->element->move_count);
			end_game(data);
		}
	}
}

void	handle_mov(int keysym, int new_x, int new_y, t_data *data)
{
	if (keysym == XK_Up || keysym == XK_w)
	{
		new_y--;
		update_map(data, new_y, new_x);
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		new_y++;
		update_map(data, new_y, new_x);
	}
	else if (keysym == XK_Left || keysym == XK_a)
	{
		new_x--;
		update_map(data, new_y, new_x);
	}
	else if (keysym == XK_Right || keysym == XK_d)
	{
		new_x++;
		update_map(data, new_y, new_x);
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
	handle_mov(keysym, new_x, new_y, data);
	return (0);
}
