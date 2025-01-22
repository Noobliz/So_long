/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:51 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/21 15:05:41 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_count_c(char **map, t_element *element)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				element->player_y = y;
				element->player_x = x;
			}
			if (map[y][x] == 'C')
				element->collectible++;
			x++;
		}
		y++;
	}
}

void	find_exit(char **map, t_element *element)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				element->exit_y = y;
				element->exit_x = x;
			}
			x++;
		}
		y++;
	}
}

char	**copy_map(char **map)
{
	int		len;
	char	**map_copy;

	len = 0;
	while (map && map[len])
	{
		len++;
	}
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		return (NULL);
	len = 0;
	while (map[len])
	{
		map_copy[len] = ft_strdup(map[len]);
		len++;
	}
	map_copy[len] = NULL;
	return (map_copy);
}

static void	walk_through(char **copy_map, int x, int y, t_element *element)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'X')
		return ;
	if (copy_map[y][x] == 'C')
		element->c_count++;
	if (copy_map[y][x] == 'E')
	{
		element->exit = 1;
		return ;
	}
	copy_map[y][x] = 'X';
	walk_through(copy_map, x + 1, y, element);
	walk_through(copy_map, x - 1, y, element);
	walk_through(copy_map, x, y + 1, element);
	walk_through(copy_map, x, y - 1, element);
}

int	valid_path(char **map, t_element *element)
{
	char	**map_copy;

	init_struct(element);
	find_player_count_c(map, element);
	find_exit(map, element);
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	walk_through(map_copy, element->player_x, element->player_y, element);
	free_map(map_copy);
	if (element->c_count == element->collectible && element->exit == 1)
		return (1);
	ft_printf("Error\nNo valid path found\n");
	return (0);
}
