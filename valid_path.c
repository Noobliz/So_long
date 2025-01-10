/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:51 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/10 15:58:38 by lguiet           ###   ########.fr       */
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
				element->y = y;
				element->x = x;
				break ;
			}
			x++;
		}
		if (map[y][x] == 'C')
			element->collectible++;
		y++;
	}
	printf("player is at x : %d et y : %d\n", element->x, element->y);
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
				break ;
			}
			x++;
		}
		y++;
	}
}
char	**copy_map(char **map)
{
	int		i;
	int		len;
	char	**map_copy;

	len = 0;
	while (map[len])
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
	return (map_copy);
}
void	walk_through(char **copy_map, int x, int y)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'X')
		return ;
	copy_map[y][x] = 'X';
	walk_through(copy_map, x + 1, y);
	walk_through(copy_map, x - 1, y);
	walk_through(copy_map, x, y + 1);
	walk_through(copy_map, x, y - 1);
}
void	valid_path(char **map, t_element *element)
{
	int collectible;
	int exit;
}