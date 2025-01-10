/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:20 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/10 12:25:15 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "so_long.h"

char	*remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
int	map_size(void)
{
	int		len;
	int		fd;
	char	*line;

	len = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		len++;
	}
	close(fd);
	return (len);
}
void	create_table(char **map, int len)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	while (i < len)
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
char	**get_map(void)
{
	int		len;
	char	**map;

	len = map_size();
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	create_table(map, len);
	return (map);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}