/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/10 14:29:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_element element;
	char **map;
	map = get_map();
	if (!is_valid(map))
	{
		printf("map not valid\n");
	}
	init_struct(&element);
	find_player_count_c(map, &element);
	free_map(map);
	return (0);
}