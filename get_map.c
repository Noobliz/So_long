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

char	**get_map(void)
{
	char	*line;
	int		fd;
	int		len;
	char	**map;
	int		i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	len = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		len++;
	}
	free(line);
	close(fd);
	map = malloc(sizeof(char *) * len + 1);
	fd = open("map.ber", O_RDONLY);
	while (i < len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}