/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hole_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:48:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 19:43:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	count_hole_num(t_game *game);
static void	create_hole(t_game *game);
static void	init_hole(t_game *game);
static void	copy_hole(t_game *game);

void	put_hole(t_game *game)
{
	int	res;

	count_hole_num(game);
	create_hole(game);
	res = -1;
	while (res == -1)
	{
		copy_map(game);
		init_hole(game);

		res = check_route(game, 2); //리턴값 -1 아닐때까지 반복하기
	}
	copy_hole(game);
}

static void	count_hole_num(t_game *game)
{
	int	empty;

	empty = game->map.width * game->map.height;
	empty -= game->map.tree_num;
	empty -= game->map.col_num;
	empty -= 2;
	game->map.hole_num = empty / 20;
}

static void	create_hole(t_game *game)
{
	int	idx;

	idx = 0;
	game->map.hole = (int **)ft_calloc(game->map.hole_num, sizeof(int *));
	if (!game->map.hole)
		error_exit(0);
	while (idx < game->map.hole_num)
	{
		game->map.hole[idx] = (int *)ft_calloc(2, sizeof(int));
		if (!game->map.hole[idx])
			error_exit(0);
		idx++;
	}
}

static void	init_hole(t_game *game)
{
	int		num;
	t_coor	coor;

	srand((unsigned int)time(0));
	coor.row = 0;
	while (coor.row < game->map.hole_num)
	{
		coor.col = 0;
		while (coor.col < 2)
		{
			if (coor.col == 0)
				num = rand() % (game->map.height - 2);
			else
				num = rand() % (game->map.width - 2);
			if (!num)
				num++;
			game->map.hole[coor.row][coor.col] = num;
			coor.col++;
		}
		game->map.tmp[game->map.hole[coor.row][0]][game->map.hole[coor.row][1]] = 'H';
		coor.row++;
	}
}

static void	copy_hole(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->map.hole_num)
	{
		game->map.map[game->map.hole[idx][0]][game->map.hole[idx][1]] = 'H';
		idx++;
	}
}