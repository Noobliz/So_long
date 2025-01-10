/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:20 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/09 16:37:42 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char	**get_map(void)
{
	char	*line;
	int		fd;
	int		len;
	char	**map;
	int		i;

	i = 0;
	len = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL); 
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		len++;
	}
	close(fd);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < len)
	{
		line = get_next_line(fd);
		if (!line)
		{
			map[i] = NULL;
			break;
		}
		map[i] = remove_newline(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}
