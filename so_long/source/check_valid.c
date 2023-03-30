/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:03:32 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/30 14:24:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_wall_row(t_map *map);
static void	check_wall_col(t_map *map);
static void	create_collection(t_map *map);
static void	init_collection(t_map *map);

void check_valid(t_map *map)
{
	if (!map->start[0])
		error_exit("No start point\n");
	if (!map->exit[0])
		error_exit("No Exit point\n");
	if (!map->col_num)
		error_exit("No collectable\n");
	check_wall_row(map);
	check_wall_col(map);
	create_collection(map);
	init_collection(map);
	check_route(map);
}

static void	check_wall_row(t_map *map)
{
	t_coor	coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.row < map->height)
	{
		if (map->map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.row++;
	}
	coor.row = 0;
	coor.col = map->width - 1;
	while (coor.row < map->height)
	{
		if (map->map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.row++;
	}
}

static void	check_wall_col(t_map *map)
{
	t_coor	coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.col < map->width)
	{
		if (map->map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.col++;
	}
	coor.row = map->height - 1;
	coor.col = 0;
	while (coor.col < map->width)
	{
		if (map->map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.col++;
	}
}

static void	create_collection(t_map *map)
{
	int	idx;

	idx = 0;
	map->collection = (int **)ft_calloc(map->col_num, sizeof(int *));
	if (!map->collection)
		error_exit(0);
	while (idx < map->col_num)
	{
		map->collection[idx] = (int *)ft_calloc(2, sizeof(int));
		if (!map->collection[idx])
		{
			while (idx--)
				free(map->collection[idx]);
			error_exit(0);
		}
		idx++;
	}
}

static void	init_collection(t_map *map)
{
	t_coor	coor;
	int		idx;

	coor.row = 0;
	idx = 0;
	while (coor.row < map->height)
	{
		coor.col = 0;
		while (coor.col < map->width)
		{
			if (map->map[coor.row][coor.col] == 'C')
			{
				map->collection[idx][0] = coor.row;
				map->collection[idx][1] = coor.col;
				idx++;
			}
			coor.col++;
		}
		coor.row++;
	}
}
