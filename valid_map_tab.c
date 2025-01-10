/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:21:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/10 14:33:48 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "so_long.h"

void	init_struct(t_element *element)
{
	element->player = 0;
	element->collectible = 0;
	element->exit = 0;
	element->exit_y = 0;
	element->exit_x = 0;
	element->x = 0;
	element->y = 0;
}
int	is_valid(char **map)
{
	if (!is_rectangular(map) || !is_surrounded_by_walls(map)
		|| !has_all_elements(map))
		return (0);
	return (1);
}
int	is_rectangular(char **map)
{
	size_t	width;
	size_t	i;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
		{
			ft_printf("the map is not rectangular\n");
			return (0);
		}
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
		{
			ft_printf("the map is not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			ft_printf("the map is not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}
bool	has_all_elements(char **map)
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
