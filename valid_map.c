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

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
	int				value;  
	struct s_map	*x;     //à droite
	struct s_map	*y;     // en bas
} t_map;

int	surrounded_by_walls(t_map *map) {
	t_map *tmp = map;
	t_map *right_side = NULL;

	// Vérification de la première ligne (haut)
	while (tmp) {
		if (tmp->value != 1) 
			return (0);
		if (!tmp->x) 
			right_side = tmp;
		tmp = tmp->x;
	}

	// Vérification de la dernière ligne (bas)
	tmp = map;
	while (tmp->y)
		tmp = tmp->y;

	while (tmp) {
		if (tmp->value != 1)
			return (0);
		tmp = tmp->x;
	}

	// Vérification des côtés gauche et droit
	t_map *left_side = map; // Début du côté gauche
	tmp = right_side;       // Début du côté droit

	while (left_side && tmp) {
		if (left_side->value != 1 || tmp->value != 1) 
			return (0);
		left_side = left_side->y;
		tmp = tmp->y;          
	}

	return (1);
}
