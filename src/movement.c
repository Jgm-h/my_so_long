/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:29 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:30 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook(int key, t_long *game)
{
	if (key == KEY_CLOSE_WINDOW)
		destroy_game(game);
	if (key == KEY_UP)
		move_up(game);
	if (key == KEY_RIGHT)
		move_right(game);
	if (key == KEY_LEFT)
		move_left(game);
	if (key == KEY_DOWN)
		move_down(game);
	return (0);
}

void	move_up(t_long *game)
{
	if (game->map[game->ppy - 1][game->ppx] == '1')
		return ;
	if (game->map[game->ppy - 1][game->ppx] == 'E' && !game->nbr_collectible)
		exit(0);
	if (game->map[game->ppy - 1][game->ppx] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * game->ppx, SIZE * (game->ppy - 1));
		game->map[game->ppy - 1][game->ppx] = '0';
		game->nbr_collectible--;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->ground->sprite, SIZE * game->ppx, SIZE * game->ppy);
	if (game->map[game->ppy][game->ppx] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->door->sprite, SIZE * game->ppx, SIZE * game->ppy);
	game->ppy--;
	game->nbr_steps++;
	ft_printf("Nombre de mouvement %i\n", game->nbr_steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->character->sprite, SIZE * game->ppx, SIZE * game->ppy);
}

void	move_down(t_long *game)
{
	if (game->map[game->ppy + 1][game->ppx] == '1')
		return ;
	if (game->map[game->ppy + 1][game->ppx] == 'E' && !game->nbr_collectible)
		exit(0);
	if (game->map[game->ppy + 1][game->ppx] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * game->ppx, SIZE * (game->ppy + 1));
		game->map[game->ppy + 1][game->ppx] = '0';
		game->nbr_collectible--;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->ground->sprite, SIZE * game->ppx, SIZE * game->ppy);
	if (game->map[game->ppy][game->ppx] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->door->sprite, SIZE * game->ppx, SIZE * game->ppy);
	game->ppy++;
	game->nbr_steps++;
	ft_printf("Nombre de mouvement %i\n", game->nbr_steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->character->sprite, SIZE * game->ppx, SIZE * game->ppy);
}

void	move_left(t_long *game)
{
	if (game->map[game->ppy][game->ppx - 1] == '1')
		return ;
	if (game->map[game->ppy][game->ppx - 1] == 'E' && !game->nbr_collectible)
		exit(0);
	if (game->map[game->ppy][game->ppx - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * (game->ppx - 1), SIZE * game->ppy);
		game->map[game->ppy][game->ppx - 1] = '0';
		game->nbr_collectible--;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->ground->sprite, SIZE * game->ppx, SIZE * game->ppy);
	if (game->map[game->ppy][game->ppx] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->door->sprite, SIZE * game->ppx, SIZE * game->ppy);
	game->ppx--;
	game->nbr_steps++;
	ft_printf("Nombre de mouvement %i\n", game->nbr_steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->character->sprite, SIZE * game->ppx, SIZE * game->ppy);
}

void	move_right(t_long *game)
{
	if (game->map[game->ppy][game->ppx + 1] == '1')
		return ;
	if (game->map[game->ppy][game->ppx + 1] == 'E' && !game->nbr_collectible)
		exit(0);
	if (game->map[game->ppy][game->ppx + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground->sprite, SIZE * (game->ppx + 1), SIZE * game->ppy);
		game->map[game->ppy][game->ppx + 1] = '0';
		game->nbr_collectible--;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->ground->sprite, SIZE * game->ppx, SIZE * game->ppy);
	if (game->map[game->ppy][game->ppx] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->door->sprite, SIZE * game->ppx, SIZE * game->ppy);
	game->ppx++;
	game->nbr_steps++;
	ft_printf("Nombre de mouvement %i\n", game->nbr_steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->character->sprite, SIZE * game->ppx, SIZE * game->ppy);
}
