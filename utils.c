/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:17:16 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/22 15:57:04 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_element *element)
{
	element->player = 0;
	element->collectible = 0;
	element->empty_space = 0;
	element->c_count = 0;
	element->exit = 0;
	element->player_x = 0;
	element->player_y = 0;
	element->move_count = 1;
}

int	map_size(char *name)
{
	int		len;
	int		fd;
	char	*line;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nOpening error\n");
		free(name);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	if (line)
		free(line);
	close(fd);
	return (len);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_width(char **map)
{
	int	j;

	j = 0;
	while (map[1][j])
		j++;
	return (j);
}
