/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:22:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:00:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int start_game(t_game *game);

int start_mlx(t_map *map)
{
	t_game *game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (free_n_print_out(2, 0, game, 0));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 32, map->height * 32, "so_long");
	game->map = map;
	img_init(game);
	draw_map(game);
	game->cur.row = map->start[0];
	game->cur.col = map->start[1];
	game->cur_dir = 1;
	start_game(game);
	mlx_loop(game->mlx);
	return (0);
}

int start_game(t_game *game)
{
	game->frame = 0;
	game->next.row = game->cur.row;
	game->next.col = game->cur.col;
	mlx_hook(game->win, 2, 0, key_press, game);
	// mlx_hook(game->win, 3, 0, key_release, game);
	mlx_loop_hook(game->mlx, standing, game);
	mlx_loop(game->mlx);
	return (0);
}