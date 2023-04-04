/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:03:32 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 18:46:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void		check_valid(t_game *game);
static void	check_wall_row(t_game *game);
static void	check_wall_col(t_game *game);
static void	create_collection(t_game *game);
static void	init_collection(t_game *game);

void	check_valid(t_game *game)
{
	if (!game->map.start[0])
		error_exit("No start point\n");
	if (!game->map.exit[0])
		error_exit("No Exit point\n");
	if (!game->map.col_num)
		error_exit("No collectable\n");
	check_wall_row(game);
	check_wall_col(game);
	create_collection(game);
	init_collection(game);
	check_route(game);
}

static void	check_wall_row(t_game *game)
{
	t_coor	coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.row < game->map.height)
	{
		if (game->map.map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.row++;
	}
	coor.row = 0;
	coor.col = game->map.width - 1;
	while (coor.row < game->map.height)
	{
		if (game->map.map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.row++;
	}
}

static void	check_wall_col(t_game *game)
{
	t_coor	coor;

	coor.row = 0;
	coor.col = 0;
	while (coor.col < game->map.width)
	{
		if (game->map.map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.col++;
	}
	coor.row = game->map.height - 1;
	coor.col = 0;
	while (coor.col < game->map.width)
	{
		if (game->map.map[coor.row][coor.col] != '1')
			error_exit("Wall not valid\n");
		coor.col++;
	}
}

static void	create_collection(t_game *game)
{
	int	idx;

	idx = 0;
	game->map.collection = (int **)ft_calloc(game->map.col_num, sizeof(int *));
	if (!game->map.collection)
		error_exit(0);
	while (idx < game->map.col_num)
	{
		game->map.collection[idx] = (int *)ft_calloc(2, sizeof(int));
		if (!game->map.collection[idx])
			error_exit(0);
		idx++;
	}
}

static void	init_collection(t_game *game)
{
	t_coor	coor;
	int		idx;

	idx = 0;
	coor.row = 0;
	while (coor.row < game->map.height)
	{
		coor.col = 0;
		while (coor.col < game->map.width)
		{
			if (game->map.map[coor.row][coor.col] == 'C')
			{
				game->map.collection[idx][0] = coor.row;
				game->map.collection[idx][1] = coor.col;
				idx++;
			}
			coor.col++;
		}
		coor.row++;
	}
}
