/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:04:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:26:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void (**get_func(int (**func)(t_game *, int, double *, double *), t_game *game, int direction))
{
	if (game->flag.fruit)
		//jump
	if (direction == 0)
		*func = walk_up;
	else if (direction == 1)
		*func = walk_left;
	else if (direction == 2)
		*func = walk_down;
	else if (direction == 3)
		*func = walk_right;
	return (0);
}

int move(t_game *game, int direction)
{
	int cnt;
	int move;
	double row;
	double col;
	int (*func)(t_game *, int, double *, double *);

	move = 8;
	if (game->flag.fruit)
		move = 11;
	row = game->cur.row * 32 + game->pos.fox_row;
	col = game->cur.col * 32 + game->pos.fox_col;
	get_func(&func, game, direction);
	game->flag.fruit = 0;
	while (cnt < move)
	{
		func(game, cnt, &row, &col);
		mlx_sync(2, game->win);
		cnt++;
	}
	return (0);
}
