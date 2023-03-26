/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:04:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 18:07:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int check_next_pos(t_game *game, int row, int col);
static void (**get_func(int (**func)(t_game *, int, double *, double *), t_game *game, int direction));

int move_ready(t_game *game, int keycode)
{
	t_coor coor;

	coor.row = game->next.row;
	coor.col = game->next.col;
	if (keycode == 0)
		coor.row--;
	else if (keycode == 1)
		coor.col--;
	else if (keycode == 2)
		coor.row++;
	else if (keycode == 3)
		coor.col++;
	if (!check_next_pos(game, coor.row, coor.col))
		move(game, keycode);
	game->cur.row = game->next.row;
	game->cur.col = game->next.col;
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
	if ((game->flag.fruit || game->flag.goal) && (direction == 1 || direction == 3))
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
	game->move_cnt++;
	printf("move : %d\n", game->move_cnt);
	return (0);
}

static int check_next_pos(t_game *game, int row, int col)
{
	if (game->map->map[row][col] == '1')
		return (-1);
	if (game->map->map[row][col] == 'C')
	{
		game->map->map[row][col] = '0';
		game->flag.fruit = 1;
	}
	if (game->map->map[row][col] == 'E')
		game->flag.goal = 1;
	game->next.row = row;
	game->next.col = col;
	return (0);
}

static void (**get_func(int (**func)(t_game *, int, double *, double *), t_game *game, int direction))
{
	if (direction == 0)
		*func = walk_up;
	else if ((game->flag.fruit || game->flag.goal) && direction == 1)
		*func = jump_left;
	else if (!game->flag.fruit && direction == 1)
		*func = walk_left;
	else if (direction == 2)
		*func = walk_down;
	else if ((game->flag.fruit || game->flag.goal) && direction == 3)
		*func = jump_right;
	else if (!game->flag.fruit && direction == 3)
		*func = walk_right;
	return (0);
}
