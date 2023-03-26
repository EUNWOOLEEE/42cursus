/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:03:32 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 16:04:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_wall_row(t_map *map)
{
	t_coor coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.row < map->height)
	{
		if (map->map[coor.row][coor.col] != '1')
			return (free_n_print_out(2, 0, map, 0));
		coor.row++;
	}
	coor.row = 0;
	coor.col = map->width - 1;
	while (coor.row < map->height)
	{
		if (map->map[coor.row][coor.col] != '1')
			return (free_n_print_out(2, 0, map, 0));
		coor.row++;
	}
	return (0);
}

int check_wall_col(t_map *map)
{
	t_coor coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.col < map->width)
	{
		if (map->map[coor.row][coor.col] != '1')
			return (free_n_print_out(2, 0, map, 0));
		coor.col++;
	}
	coor.row = map->height - 1;
	coor.col = 0;
	while (coor.col < map->width)
	{
		if (map->map[coor.row][coor.col] != '1')
			return (free_n_print_out(2, 0, map, 0));
		coor.col++;
	}
	return (0);
}

int create_collection(t_map *map, int col_num)
{
	int idx;

	idx = 0;
	map->collection = (int **)ft_calloc(col_num, sizeof(int *));
	if (!map->collection)
		return (-1);
	while (idx < col_num)
	{
		map->collection[idx] = (int *)ft_calloc(2, sizeof(int));
		if (!map->collection[idx])
		{
			while (idx--)
				free(map->collection[idx]);
			return (free_n_print_out(2, 0, map, 0));
		}
		idx++;
	}
	return (0);
}

void init_collection(t_map *map)
{
	t_coor coor;
	int idx;

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
