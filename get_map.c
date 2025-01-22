/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:20 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/22 16:15:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static void	quit_clear(char **map, char *name)
{
	free(name);
	free_map(map);
	ft_printf("Error\n");
	exit(0);
}

static void	create_table(char **map, int len, char *name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		quit_clear(map, name);
	while (i <= len)
	{
		line = get_next_line(fd);
		if (!line)
		{
			map[i] = NULL;
			break ;
		}
		map[i] = remove_newline(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
}

char	**get_map(char *name)
{
	int		len;
	char	**map;

	len = map_size(name);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
	{
		free(name);
		return (NULL);
	}
	create_table(map, len, name);
	if (!map || !*map)
	{
		free(name);
		free(map);
		ft_printf("Error\nEmpty Map\n");
		exit(0);
	}
	free(name);
	return (map);
}
