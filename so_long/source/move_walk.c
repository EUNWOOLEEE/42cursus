/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:00:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:00:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int walk_up(t_game *game, int walk, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	*col = (game->cur.col * 32) + game->pos.fox_col;
	draw_sprite(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_sprite(game, game->map_img[0], (game->next.row + 1) * 32, game->next.col * 32);
	while (cnt--)
		draw_sprite(game, game->walk[game->cur_dir][walk], *row, *col);
	*row -= 4;
	return (0);
}

int walk_left(t_game *game, int walk, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	if (!walk || walk == 4)
		*row = (game->cur.row * 32) + game->pos.fox_row;
	else
		*row = (game->cur.row * 32) + game->pos.fox_row - 32 * 0.02;
	draw_sprite(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_sprite(game, game->map_img[0], game->next.row * 32, (game->next.col + 1) * 32);
	while (cnt--)
		draw_sprite(game, game->walk[game->cur_dir][walk], *row, *col);
	*col -= 4;
	return (0);
}

int walk_down(t_game *game, int walk, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	*col = (game->cur.col * 32) + game->pos.fox_col;
	draw_sprite(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_sprite(game, game->map_img[0], (game->next.row - 1) * 32, game->next.col * 32);
	while (cnt--)
		draw_sprite(game, game->walk[game->cur_dir][walk], *row, *col);
	*row += 4;
	return (0);
}

int walk_right(t_game *game, int walk, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	if (!walk || walk == 4)
		*row = (game->cur.row * 32) + game->pos.fox_row;
	else
		*row = (game->cur.row * 32) + game->pos.fox_row - 32 * 0.02;
	draw_sprite(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_sprite(game, game->map_img[0], game->next.row * 32, (game->next.col - 1) * 32);
	while (cnt--)
		draw_sprite(game, game->walk[game->cur_dir][walk], *row, *col);
	*col += 4;
	return (0);
}
