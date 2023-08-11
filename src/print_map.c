/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:35 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:37 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			img_to_window(game->map[i][j], game, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

void	img_to_window(char c, t_long *game, int i, int j)
{
	if (c == 'C' || c == '0' || c == 'P' || c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * j, SIZE * i);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->collectible->sprite, SIZE * j, SIZE * i);
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall->sprite, SIZE * j, SIZE * i);
	if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * j, SIZE * i);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->door->sprite, SIZE * j, SIZE * i);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character->sprite, SIZE * j, SIZE * i);
}
