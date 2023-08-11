/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:47:42 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/08/08 23:47:44 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_long	game;

	if (argc != 2)
	{
		perror("Error, missing map\n");
		exit(0);
	}
	init_game(&game);
	init_map(&game, argv);
	check_map(&game);
	print_map(&game);
	mlx_hook(game.win_ptr, 2, 0, hook, &game);
	mlx_hook(game.win_ptr, 17, 0, destroy_game, &game);
	mlx_loop(game.mlx_ptr);
	destroy_game(&game);
}
