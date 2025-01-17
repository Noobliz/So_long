/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:21:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/17 14:43:21 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	size_t	width;
	size_t	i;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	size_t	width;
	size_t	height;
	size_t	i;

	width = ft_strlen(map[0]);
	height = 0;
	i = 0;
	while (map[height])
		height++;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	has_all_elements(char **map)
{
	t_element	element;
	int			i;
	int			j;

	init_struct(&element);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				element.player++;
			if (map[i][j] == 'C')
				element.collectible++;
			if (map[i][j] == 'E')
				element.exit++;
			j++;
		}
		i++;
	}
	return (element.player == 1 && element.collectible >= 1
		&& element.exit == 1);
}
int	valid_characters(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'E' && map[y][x] != 'C'
				&& map[y][x] != '1' && map[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid(char **map)
{
	if (!is_rectangular(map))
	{
		ft_printf("Error\n");
		ft_printf("Map is not rectangular\n");
		return (0);
	}
	if (!is_surrounded_by_walls(map))
	{
		ft_printf("Error\n");
		ft_printf("Map is not surrounded by walls\n");
		return (0);
	}
	if (!has_all_elements(map))
	{
		ft_printf("Error\n");
		ft_printf("Map do not have required elements\n");
		return (0);
	}
	if (!valid_characters(map))
	{
		ft_printf("Error\n");
		ft_printf("Map has invalid characters\n");
		return (0);
	}
	return (1);
}
