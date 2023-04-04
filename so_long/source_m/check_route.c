/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:10:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 18:46:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void		check_route(t_game *game);
static void	bfs(t_game *game, t_coor *queue, int front, int rear);
static int	*set_direction(int flag);
static int	apply_direction(t_game *game, int next_row, int next_col);
static void	check_res(t_game *game);

void	check_route(t_game *game)
{
	int		i;
	t_coor	*queue;

	queue = (t_coor *)ft_calloc
		(game->map.height * game->map.width, sizeof(t_coor));
	if (!queue)
		error_exit(0);
	i = 0;
	while (i < game->map.height)
	{
		ft_memmove(game->map.tmp[i], game->map.map[i],
			sizeof(char) * game->map.width);
		i++;
	}
	queue[0].row = game->map.start[0];
	queue[0].col = game->map.start[1];
	game->map.tmp[game->map.start[0]][game->map.start[1]] = '-';
	bfs(game, queue, 0, 1);
	check_res(game);
	free(queue);
}

static void	bfs(t_game *game, t_coor *queue, int front, int rear)
{
	int		cnt;
	t_coor	cur;
	t_coor	next;
	int		*d_row;
	int		*d_col;

	d_row = set_direction(1);
	d_col = set_direction(2);
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

static int	*set_direction(int flag)
{
	int	*tmp;

	tmp = (int *)ft_calloc(4, sizeof(int));
	if (!tmp)
		error_exit(0);
	if (flag == 1)
	{
		tmp[0] = -1;
		tmp[1] = 1;
		tmp[2] = 0;
		tmp[3] = 0;
	}
	else if (flag == 2)
	{
		tmp[0] = 0;
		tmp[1] = 0;
		tmp[2] = -1;
		tmp[3] = 1;
	}
	return (tmp);
}

static int	apply_direction(t_game *game, int next_row, int next_col)
{
	if (next_row < 0 || next_col < 0
		|| next_row >= game->map.height || next_col >= game->map.width)
		return (-1);
	if (game->map.tmp[next_row][next_col] == '0'
		|| game->map.tmp[next_row][next_col] == 'C'
		|| game->map.tmp[next_row][next_col] == 'E')
	{
		game->map.tmp[next_row][next_col] = '-';
		return (1);
	}
	return (0);
}

static void	check_res(t_game *game)
{
	int	row;

	row = 0;
	if (game->map.tmp[game->map.exit[0]][game->map.exit[1]] != '-')
		error_exit("Unable to access exit point\n");
	while (row < game->map.col_num)
	{
		if (game->map.tmp[game->map.collection[row][0]]
			[game->map.collection[row][1]] != '-')
			error_exit("Unable to access collectable\n");
		row++;
	}
}
