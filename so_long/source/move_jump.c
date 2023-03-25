/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:01:08 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/25 17:19:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int jump_left(t_game *game, int jump, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	*row = (game->cur.row * 32);// + game->pos.fox_row;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0], game->next.row * 32, (game->next.col + 1) * 32);
	while (cnt--)
		draw_img(game, game->jump[game->cur_dir][jump], *row, *col);
	*col -= 3;
	return (0);
}

int jump_right(t_game *game, int jump, double *row, double *col)
{
	int cnt;

	cnt = 1200;
	*row = (game->cur.row * 32);// + game->pos.fox_row;
	draw_img(game, game->map_img[0], game->next.row * 32, game->next.col * 32);
	draw_img(game, game->map_img[0], game->next.row * 32, (game->next.col - 1) * 32);
	while (cnt--)
		draw_img(game, game->jump[game->cur_dir][jump], *row, *col);
	*col += 3;
	return (0);
}
