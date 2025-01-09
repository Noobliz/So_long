/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:21:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/09 17:25:11 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "so_long.h"

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

	width = ft_strlen(map[0]); // longueur premiere ligne
	height = 0;
	i = 0;
	while (map[height]) // largeur
		height++;
	// verifie premiere et derniere ligne
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	// verifie les cotes
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}
bool	has_all_elements(char **map)
{
	int	player;
	int	collectible;
	int	exit;
	int	i;
	int	j;

	player = 0;
	collectible = 0;
	exit = 0;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'C')
				collectible++;
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (player == 1 && collectible >= 1 && exit == 1);
}
