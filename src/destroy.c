/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:01 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:03 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	destroy_game(t_long *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

void	error_management(t_long *game, int error)
{
	if (error == MEMORY)
		ft_printf("%s", "Error \nMemory problem");
	if (error == NAME)
		ft_printf("%s", "Error \nFile name problem");
	if (error == MAP)
		ft_printf("%s" "%s", "Error \nMap problem");
	if (error == PATH)
		ft_printf("%s", "Error \nPathing problem");
	destroy_game(game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map[i]);
	free(map);
}
