/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:10:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 20:56:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int			check_route(t_game *game, int flag);
static void	bfs(t_game *game, t_coor *queue, int front, int rear);
static void	set_direction(int **d_row, int **d_col);
static int	apply_direction(t_game *game, int next_row, int next_col);
static int	check_res(t_game *game, int flag);

int	check_route(t_game *game, int flag)
{
	t_coor	*queue;

	queue = (t_coor *)ft_calloc
		(game->map.height * game->map.width, sizeof(t_coor));
	if (!queue)
		error_exit(0);
	game->map.flag_exit = 0;
	bfs(game, queue, 0, 1);
	free(queue);
	return (check_res(game, flag));
}

static void	bfs(t_game *game, t_coor *queue, int front, int rear)
{
	int		cnt;
	t_coor	cur;
	t_coor	next;
	int		*d_row;
	int		*d_col;

	set_direction(&d_row, &d_col);
	queue[0].row = game->map.start[0];
	queue[0].col = game->map.start[1];
	game->map.tmp[game->map.start[0]][game->map.start[1]] = '-';
	while (front < rear)
	{
		cnt = 0;
		cur = queue[front++];
		while (cnt < 4)
		{
			next.row = cur.row + d_row[cnt];
			next.col = cur.col + d_col[cnt];
			if (apply_direction(game, next.row, next.col) == 1)
				queue[rear++] = next;
			cnt++;
		}
	}
	free(d_row);
	free(d_col);
}

static void	set_direction(int **d_row, int **d_col)
{
	*d_row = (int *)ft_calloc(4, sizeof(int));
	*d_col = (int *)ft_calloc(4, sizeof(int));
	if (!*d_row || !*d_col)
		error_exit(0);
	(*d_row)[0] = -1;
	(*d_row)[1] = 1;
	(*d_col)[2] = -1;
	(*d_col)[3] = 1;
}

static int	apply_direction(t_game *game, int next_row, int next_col)
{
	if (next_row < 0 || next_col < 0
		|| next_row >= game->map.height || next_col >= game->map.width)
		return (-1);
	if (game->map.tmp[next_row][next_col] == 'E')
	{
		game->map.flag_exit++;
		return (-1);
	}
	if (game->map.tmp[next_row][next_col] == '0'
		|| game->map.tmp[next_row][next_col] == 'C')
	{
		game->map.tmp[next_row][next_col] = '-';
		return (1);
	}
	return (0);
}

static int	check_res(t_game *game, int flag)
{
	int	row;

	row = 0;
	if (!game->map.flag_exit)
	{
		if (flag == 1)
			error_exit("Unable to access exit point\n");
		return (-1);
	}
	while (row < game->map.col_num)
	{
		if (game->map.tmp[game->map.collection[row][0]]
			[game->map.collection[row][1]] != '-')
		{
			if (flag == -1)
				error_exit("Unable to access collectable\n");
			return (-1);
		}
		row++;
	}
	return (0);
}
