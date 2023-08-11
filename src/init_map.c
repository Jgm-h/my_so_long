/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:17 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:18 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_long *game, char **argv)
{
	game->first_map = read_fd(argv[1], game);
	if (!game->first_map)
		error_management(game, MEMORY);
	game->map = fill_map(game->first_map, game);
	count_collectibles(game);
}

void	count_collectibles(t_long *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				k++;
			j++;
		}
		i++;
		j = 0;
	}
	game->nbr_collectible = k;
	game->nbr_c_check = k;
}

char	*read_fd(char *map, t_long *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b' || \
	map[i - 4] != '.')
		error_management(game, NAME);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		destroy_game(game);
	line = get_next_line(fd);
	if (!line)
		error_management(game, MEMORY);
	close(fd);
	return (line);
}

int	elements_per_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

int	number_of_lines(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == '\n')
			i++;
		line++;
	}
	if (*line == '\0')
		i++;
	return (i);
}
