/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:34:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/10 14:32:48 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int	player;
	int	collectible;
	int	exit;
	int	exit_y;
	int	exit_x;
	int	x;
	int	y;
}		t_element;

char	**get_map(void);
void	free_map(char **map);
int		is_rectangular(char **map);
int		is_surrounded_by_walls(char **map);
bool	has_all_elements(char **map);
int		is_valid(char **map);
void	find_player_count_c(char **map, t_element *element);
void	init_struct(t_element *element);
#endif