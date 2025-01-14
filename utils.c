/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:17:16 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/13 14:18:47 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "LIBFT/libft.h"

void	init_struct(t_element *element)
{
	element->player = 0;
	element->collectible = 0;
	element->exit = 0;
	element->exit_y = 0;
	element->exit_x = 0;
	element->player_x = 0;
	element->player_y = 0;
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
void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		// printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}