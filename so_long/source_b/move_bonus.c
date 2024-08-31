/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:04:16 by eunwolee          #+#    #+#             */
/*   Updated: 2024/08/31 14:59:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int			move_ready(t_game *game, int keycode);
static int	move(t_game *game, int direction);
static int	check_next_pos(t_game *game, int row, int col);
static int	(*get_func(t_game *game, int direction))(t_game *game,
				int jump, double *row, double *col);

int	move_ready(t_game *game, int keycode)
{
	t_coor	coor;

	coor.row = game->next.row;
	coor.col = game->next.col;
	if (keycode == MOVE_UP)
		coor.row--;
	else if (keycode == MOVE_LEFT)
		coor.col--;
	else if (keycode == MOVE_DOWN)
		coor.row++;
	else if (keycode == MOVE_RIGHT)
		coor.col++;
	if (!check_next_pos(game, coor.row, coor.col))
		move(game, keycode);
	game->cur.row = game->next.row;
	game->cur.col = game->next.col;
	return (0);
}

static int	move(t_game *game, int direction)
{
	int		cur_frame;
	int		max_frame;
	double	row;
	double	col;
	int		(*func)(t_game *, int, double *, double *);

	cur_frame = 0;
	max_frame = 8;
	if ((game->flag.fruit || game->flag.goal)
		&& (direction == MOVE_LEFT || direction == MOVE_RIGHT))
		max_frame = 11;
	row = game->cur.row * SPRITE_SIZE;
	col = game->cur.col * SPRITE_SIZE;
	func = get_func(game, direction);
	game->flag.fruit = FALSE;
	while (cur_frame < max_frame)
	{
		func(game, cur_frame, &row, &col);
		mlx_sync(2, game->win);
		cur_frame++;
	}
	game->move_cnt++;
	print_move(game);
	return (0);
}

static int	(*get_func(t_game *game, int direction))
				(t_game *game, int jump, double *row, double *col)
{
	if (direction == MOVE_UP)
		return (walk_up);
	else if ((game->flag.fruit || game->flag.goal) && direction == MOVE_LEFT)
		return (jump_left);
	else if (!game->flag.fruit && direction == MOVE_LEFT)
		return (walk_left);
	else if (direction == MOVE_DOWN)
		return (walk_down);
	else if ((game->flag.fruit || game->flag.goal) && direction == MOVE_RIGHT)
		return (jump_right);
	else if (!game->flag.fruit && direction == MOVE_RIGHT)
		return (walk_right);
	return (0);
}

static int	check_next_pos(t_game *game, int row, int col)
{
	if (game->map.map[row][col] == '1')
		return (-1);
	if (game->map.map[row][col] == 'H')
	{
		game->flag.hole = 1;
		return (-1);
	}
	if (game->map.map[row][col] == 'E')
	{
		if (game->map.col_num)
			return (-1);
		game->flag.goal = 1;
	}
	if (game->map.map[row][col] == 'C')
	{
		game->map.map[row][col] = '0';
		game->flag.fruit = TRUE;
		game->map.col_num--;
	}
	game->next.row = row;
	game->next.col = col;
	return (0);
}
