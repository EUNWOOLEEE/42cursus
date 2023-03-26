/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:10:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 16:06:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int bfs(t_map *map, t_coor *queue, int front, int rear);
static int *set_direction(int flag);
static int apply_direction(t_map *map, int next_row, int next_col);
static int check_res(t_map *map);

int check_route(t_map *map)
{
	t_map *tmp;
	t_coor *queue;

	tmp = (t_map *)ft_calloc(1, sizeof(t_map));
	queue = (t_coor *)ft_calloc(map->height * map->width, sizeof(t_coor));
	if (!tmp || !queue)
		return (free_n_print_out(2, 0, tmp, queue));
	ft_memmove(tmp, map, sizeof(t_map));
	create_map(tmp);
	for(int i = 0; i < map->height; i++)
		ft_memmove(tmp->map[i], map->map[i], sizeof(char) * map->width);
	queue[0].row = map->start[0];
	queue[0].col = map->start[1];
	tmp->map[map->start[0]][map->start[1]] = '-';
	if (bfs(tmp, queue, 0, 1) == -1)
		return (free_n_print_out(2, 0, tmp, queue));
	if (check_res(tmp) == -1)
		return (free_n_print_out(2, 0, tmp, queue));
	return (free_n_print_out(1, 0, tmp, queue));
}

static int bfs(t_map *map, t_coor *queue, int front, int rear)
{
	int cnt;
	t_coor cur;
	t_coor next;
	int *d_row;
	int *d_col;

	d_row = set_direction(1);
	d_col = set_direction(2);
	if (!d_row || !d_col)
		return (free_n_print_out(2, 0, d_row, d_col));
	while (front < rear)
	{
		cur = queue[front++];
		cnt = 0;
		while (cnt < 4)
		{
			next.row = cur.row + d_row[cnt];
			next.col = cur.col + d_col[cnt];
			if (apply_direction(map, next.row, next.col) == 1)
				queue[rear++] = next;
			cnt++;
		}
	}
	return (free_n_print_out(1, 0, d_row, d_col));
}

static int *set_direction(int flag)
{
	int *tmp;

	tmp = (int *)ft_calloc(4, sizeof(int));
	if (!tmp)
		return (0);
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
	else
		return (0);
	return (tmp);
}

static int apply_direction(t_map *map, int next_row, int next_col)
{
	if (next_row < 0 || next_col < 0 || next_row >= map->height || next_col >= map->width)
		return (-1);
	if (map->map[next_row][next_col] == '0'
		|| map->map[next_row][next_col] == 'C' || map->map[next_row][next_col] == 'E')
	{
		map->map[next_row][next_col] = '-';
		return (1);
	}
	return (0);
}

static int check_res(t_map *map)
{
	int row;

	if (map->map[map->exit[0]][map->exit[1]] != '-')
		return (-1);
	row = 0;
	while (row < map->col_num)
	{
		if (map->map[map->collection[row][0]][map->collection[row][1]] != '-')
			return (-1);
		row++;
	}
	return (0);
}
