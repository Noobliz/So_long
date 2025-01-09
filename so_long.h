/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:34:12 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/09 17:01:13 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdbool.h>

char	**get_map(void);
void	free_map(char **map);
int	is_rectangular(char **map);
int	is_surrounded_by_walls(char **map);
bool	has_all_elements(char **map);
int	is_valid(char **map);
#endif