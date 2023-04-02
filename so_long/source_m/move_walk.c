/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:00:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/02 15:35:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	walk_up(t_game *game, int walk, double *row, double *col);
int	walk_left(t_game *game, int walk, double *row, double *col);
int	walk_down(t_game *game, int walk, double *row, double *col);
int	walk_right(t_game *game, int walk, double *row, double *col);

int	walk_up(t_game *game, int walk, double *row, double *col)
{
	int	cnt;

	cnt = 1200;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0],
		(game->next.row + 1) * 32, game->next.col * 32);
	while (cnt--)
		draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	*row -= 4;
	return (0);
}

int	walk_left(t_game *game, int walk, double *row, double *col)
{
	int	cnt;

	cnt = 1200;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0],
		game->next.row * 32, (game->next.col + 1) * 32);
	while (cnt--)
		draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	*col -= 4;
	return (0);
}

int	walk_down(t_game *game, int walk, double *row, double *col)
{
	int	cnt;

	cnt = 1200;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0],
		(game->next.row - 1) * 32, game->next.col * 32);
	while (cnt--)
		draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	*row += 4;
	return (0);
}

int	walk_right(t_game *game, int walk, double *row, double *col)
{
	int	cnt;

	cnt = 1200;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0],
		game->next.row * 32, (game->next.col - 1) * 32);
	while (cnt--)
		draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	*col += 4;
	return (0);
}
