/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:46:52 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:46:55 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_long *game)
{
	char	**map_double;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	check_elements_length(game, i, j, length);
	check_walls(game);
	map_double = double_map(game);
	if (!check_path(game->ppy, game->ppx, map_double, game))
		error_management(game, PATH);
	init_window(game);
	free_map(map_double);
}

int	check_path(int ppy, int ppx, char **map, t_long *game)
{
	if (map[ppy][ppx] == 'C')
		game->nbr_c_check--;
	if (map[ppy][ppx] == 'E')
		game->nbr_d_check++;
	if (map[ppy][ppx] == '1')
		return (0);
	if (map[ppy][ppx] == 'C' || map[ppy][ppx] == 'E' || map[ppy][ppx] == 'P' || \
		map[ppy][ppx] == '0')
		map[ppy][ppx] = 'x';
	if (map[ppy][ppx + 1] != '1' && map[ppy][ppx + 1] != 'x')
		check_path(ppy, ppx + 1, map, game);
	if (map[ppy][ppx - 1] != '1' && map[ppy][ppx - 1] != 'x')
		check_path(ppy, ppx - 1, map, game);
	if (map[ppy + 1][ppx] != '1' && map[ppy + 1][ppx] != 'x')
		check_path(ppy + 1, ppx, map, game);
	if (map[ppy - 1][ppx] != '1' && map[ppy - 1][ppx] != 'x')
		check_path(ppy - 1, ppx, map, game);
	if (game->nbr_c_check || game->nbr_d_check != 1)
		return (0);
	return (1);
}

void	check_elements_length(t_long *game, int i, int j, int length)
{
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map \
			[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
				error_management(game, MAP);
			check_elements(game, i, j);
			j++;
		}
		if (i && length != j)
			error_management(game, MAP);
		length = j;
		i++;
		j = 0;
	}
	if (game->nbr_player > 1 || game->nbr_collectible < 1 || game->nbr_door > 1)
		error_management(game, MAP);
	game->map_height = i;
	game->map_width = length;
}

void	check_elements(t_long *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->ppy = i;
		game->ppx = j;
		game->nbr_player++;
	}
	if (game->map[i][j] == 'E')
		game->nbr_door++;
}

void	check_walls(t_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (!i || !j || i == game->map_height - 1 || j == game->map_width)
			{
				if (game->map[i][j] != '1')
					error_management(game, MAP);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
