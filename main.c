/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:23 by lguiet            #+#    #+#             */
/*   Updated: 2025/01/22 13:27:22 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*parse_argv(int argc, char **argv)
{
	int		len;
	int		i;
	char	*name;

	if (argc != 2)
	{
		ft_printf("Error\nToo little or too many arguments\n");
		return (0);
	}
	i = 0;
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e' || argv[1][len
		- 3] != 'b' || argv[1][len - 4] != '.')
	{
		ft_printf("Error\nMap's name incorrect\n");
		return (NULL);
	}
	name = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(name, argv[1], len + 1);
	return (name);
}

int	main(int argc, char **argv)
{
	t_img		img;
	t_data		data;
	t_element	element;
	char		*name;

	name = parse_argv(argc, argv);
	if (!name)
		return (0);
	init_struct(&element);
	data.img = &img;
	data.map = get_map(name);
	if (!data.map)
		return (0);
	if (!is_valid(data.map) || !valid_path(data.map, &element))
	{
		free_map(data.map);
		return (0);
	}
	img_init(&data);
	data.element = &element;
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window, DestroyNotify, NoEventMask, &handle_close, &data);
	display_map(data.map, data);
	mlx_loop(data.mlx);
	return (0);
}
