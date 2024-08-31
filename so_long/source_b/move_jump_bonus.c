/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_jump_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:01:08 by eunwolee          #+#    #+#             */
/*   Updated: 2024/08/31 14:47:09 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	jump_left(t_game *game, int jump, double *row, double *col);
int	jump_right(t_game *game, int jump, double *row, double *col);

int	jump_left(t_game *game, int jump, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, (game->next.col + 1) * SPRITE_SIZE);
	draw_img(game, game->jump[game->cur_dir][jump], *row, *col);
	usleep(SLEEP_USEC);
	*col -= 3;
	return (0);
}

int	jump_right(t_game *game, int jump, double *row, double *col)
{
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, game->next.col * SPRITE_SIZE);
	draw_img(game, game->map_img[0], game->next.row * SPRITE_SIZE, (game->next.col - 1) * SPRITE_SIZE);
	draw_img(game, game->jump[game->cur_dir][jump], *row, *col);
	usleep(SLEEP_USEC);
	*col += 3;
	return (0);
}
