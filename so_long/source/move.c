/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:04:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/25 18:13:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void (**get_func(int (**func)(t_game *, int, double *, double *), t_game *game, int direction))
{
	if (direction == 0)
		*func = walk_up;
	else if ((game->flag.fruit || game->flag.exit) && direction == 1)
		*func = jump_left;
	else if (!game->flag.fruit && direction == 1)
		*func = walk_left;
	else if (direction == 2)
		*func = walk_down;
	else if ((game->flag.fruit || game->flag.exit) && direction == 3)
		*func = jump_right;
	else if (!game->flag.fruit && direction == 3)
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

	cnt = 0;
	move = 8;
	if (game->flag.fruit || game->flag.exit)
		move = 11;
	row = game->cur.row * 32;
	col = game->cur.col * 32;
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
