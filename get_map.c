/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:20 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/22 13:32:16 by lguiet           ###   ########.fr       */
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

static void	create_table(char **map, int len, char *name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		free(name);
		free_map(map);
		exit(EXIT_FAILURE);
	}
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
	free(name);
	return (map);
}
