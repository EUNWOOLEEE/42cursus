/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_walk_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:00:49 by eunwolee          #+#    #+#             */
/*   Updated: 2024/08/31 14:47:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	walk_up(t_game *game, int walk, double *row, double *col);
int	walk_left(t_game *game, int walk, double *row, double *col);
int	walk_down(t_game *game, int walk, double *row, double *col);
int	walk_right(t_game *game, int walk, double *row, double *col);

int	walk_up(t_game *game, int walk, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], (game->next.row + 1) * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	usleep(SLEEP_USEC);
	*row -= 4;
	return (0);
}

int	walk_left(t_game *game, int walk, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, (game->next.col + 1) * SPRITE_SIZE);
	draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	usleep(SLEEP_USEC);
	*col -= 4;
	return (0);
}

int	walk_down(t_game *game, int walk, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], (game->next.row - 1) * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	usleep(SLEEP_USEC);
	*row += 4;
	return (0);
}

int	walk_right(t_game *game, int walk, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, (game->next.col - 1) * SPRITE_SIZE);
	draw_img(game, game->walk[game->cur_dir][walk], *row, *col);
	usleep(SLEEP_USEC);
	*col += 4;
	return (0);
}
