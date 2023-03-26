/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:22:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 18:38:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int game_start(t_game *game);
static void set_value(t_game *game);
static int main_loop(t_game *game);

int create_mlx(int fd)
{
	t_game *game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (-1);
	game->map = get_map(fd);
	if (!game->map)
		return (free_n_print_out(2, 0, game, 0));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 32, game->map->height * 32, "so_long");
	if (init_img(game) == -1)
		return (free_n_print_out(2, 0, game, game->map));
	draw_map(game);
	set_value(game);
	game_start(game);
	return (0);
}

static int game_start(t_game *game)
{
	mlx_hook(game->win, 2, 0, key_press, game);
	// mlx_hook(game->win, 3, 0, key_release, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

static int main_loop(t_game *game)
{
	standing(game);
	if (game->flag.goal || game->flag.exit)
		game_end(game);
	return (0);
}

static void set_value(t_game *game)
{
	game->frame = 0;
	game->move_cnt = 0;
	game->flag.fruit = 0;
	game->flag.exit = 0;
	game->flag.motion = 0;
	game->cur.row = game->map->start[0];
	game->cur.col = game->map->start[1];
	game->next.row = game->cur.row;
	game->next.col = game->cur.col;
	if (game->map->start[1] < game->map->width / 2)
		game->cur_dir = 1;
	else
		game->cur_dir = 0;
}