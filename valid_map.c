/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:46:29 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/07 16:05:50 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	int				value;
	struct s_map	*x;
	struct s_map	*y;
}					t_map;

int	surrounded_by_walls(t_map *map)
{
	t_map *tmp;
	t_map *right_side;
	t_map *end;
	tmp = map;
	// verif de la premiere ligne
	while (tmp && tmp->x)
	{
		if (tmp->x->value != 1)
		{
			return (0);
		}
		tmp = tmp->x;
	}
	right_side = tmp;
	tmp = map->y;

	while (tmp->y)
		tmp = tmp->y;
	// verif de la derniere ligne
	while (tmp && tmp->x)
	{
		if (tmp->x->value != 1)
		{
			return (0);
		}
		tmp = tmp->x;
	}
	tmp = map;
	// verif cote gauche et droit
	while ((tmp && tmp->y) || (right_side && right_side->y))
	{
		if (tmp->y->value != 1 || right_side->y->value != 1)
			return (0);
		if (tmp)
			tmp = tmp->y;
		if (right_side)
			right_side = right_side->y;
	}
	return (1);
}