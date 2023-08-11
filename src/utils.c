/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:52 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:59 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_long *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, SIZE * game->map_width, \
		SIZE * game->map_height, "Welcome to Long_Long!");
	if (!game->win_ptr)
		error_management(game, MEMORY);
}

char	**double_map(t_long *game)
{
	int		i;
	int		j;
	char	**map_double;

	i = 0;
	j = 0;
	map_double = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_double)
		error_management(game, MEMORY);
	while (game->map[i])
	{
		map_double[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!map_double[i])
			error_management(game, MEMORY);
		while (game->map[i][j])
		{
			map_double[i][j] = game->map[i][j];
			j++;
		}
		map_double[i][j] = '\0';
		i++;
		j = 0;
	}
	map_double[i] = NULL;
	return (map_double);
}

char	**fill_map(char *line, t_long *game)
{
	char	**map;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = line;
	map = (char **)malloc(sizeof(char *) * (number_of_lines(line) + 1));
	if (!map)
		error_management(game, MEMORY);
	while (*ptr)
	{
		map[i] = (char *)malloc(sizeof(char) * elements_per_line(ptr) + 1);
		if (!map[i])
			error_management(game, MEMORY);
		while (*ptr != '\n' && *ptr)
			map[i][j++] = *ptr++;
		map[i++][j] = '\0';
		if (*ptr)
			ptr++;
		j = 0;
	}
	map[i] = NULL;
	return (map);
}
