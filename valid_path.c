/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:51 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/15 15:57:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
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

void	walk_through(char **copy_map, int x, int y, int *c_count, int *exit)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'X')
		return ;
	if (copy_map[y][x] == 'C')
		(*c_count)++;
	if (copy_map[y][x] == 'E')
	{
		*exit = 1;
		return ;
	}
	copy_map[y][x] = 'X';
	walk_through(copy_map, x + 1, y, c_count, exit);
	walk_through(copy_map, x - 1, y, c_count, exit);
	walk_through(copy_map, x, y + 1, c_count, exit);
	walk_through(copy_map, x, y - 1, c_count, exit);
}

int	valid_path(char **map, t_element *element)
{
	int		c_count;
	int		exit;
	char	**map_copy;

	exit = 0;
	c_count = 0;
	init_struct(element);
	find_player_count_c(map, element);
	find_exit(map, element);
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	walk_through(map_copy, element->player_x, element->player_y, &c_count,
		&exit);
	free_map(map_copy);
	if (c_count == element->collectible && exit == 1)
		return (1);
	ft_printf("Error\nNo valid path found");
	return (0);
}
