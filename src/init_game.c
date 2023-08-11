/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:08 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:10 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_long *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_management(game, MEMORY);
	init_sprites_path(game);
	init_sprites_image(game);
	init_values(game);
}

void	init_sprites_path(t_long *game)
{
	game->ground = malloc(sizeof(t_sprite));
	if (!game->ground)
		error_management(game, MEMORY);
	game->wall = malloc(sizeof(t_sprite));
	if (!game->wall)
		error_management(game, MEMORY);
	game->collectible = malloc(sizeof(t_sprite));
	if (!game->collectible)
		error_management(game, MEMORY);
	game->character = malloc(sizeof(t_sprite));
	if (!game->character)
		error_management(game, MEMORY);
	game->door = malloc(sizeof(t_sprite));
	if (!game->door)
		error_management(game, MEMORY);
	game->ground->path = GROUND;
	game->wall->path = WALL;
	game->collectible->path = COLLECTIBLE;
	game->character->path = CHARACTER;
	game->door->path = DOOR;
}

void	init_sprites_image(t_long *game)
{
	game->ground->sprite = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->ground->path, &game->ground->width, &game->ground->length);
	if (!game->ground->sprite)
		error_management(game, MEMORY);
	game->wall->sprite = mlx_xpm_file_to_image(game->mlx_ptr, game->wall->path, \
		&game->wall->width, &game->wall->length);
	if (!game->wall->sprite)
		error_management(game, MEMORY);
	game->collectible->sprite = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->collectible->path, &game->collectible->width, \
	&game->collectible->length);
	if (!game->collectible->sprite)
		error_management(game, MEMORY);
	game->character->sprite = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->character->path, &game->character->width, &game->character->length);
	if (!game->character->sprite)
		error_management(game, MEMORY);
	game->door->sprite = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->door->path, &game->door->width, &game->door->length);
	if (!game->door->sprite)
		error_management(game, MEMORY);
}

void	init_values(t_long *game)
{
	game->nbr_collectible = 0;
	game->nbr_player = 0;
	game->nbr_door = 0;
	game->nbr_d_check = 0;
	game->nbr_steps = 0;
}
