/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:30:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 15:21:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int get_element(t_game *game, char c, t_coor coor, int fruit_num);
static void set_pos(t_game *game, char c, double *row, double *col);

void draw_img(t_game *game, t_img img, double row, double col)
{
	mlx_put_image_to_window(game->mlx, game->win, img.img_ptr, col, row);
}

int draw_map(t_game *game)
{
	int fruit_num;
	t_coor coor;

	fruit_num = 0;
	coor.row = 0;
	while (coor.row < game->map->height)
	{
		coor.col = 0;
		while (coor.col < game->map->width)
		{
			get_element(game, game->map->map[coor.row][coor.col], coor, fruit_num);
			if (game->map->map[coor.row][coor.col] == 'C')
				fruit_num = (fruit_num + 1) % 5;
			coor.col++;
		}
		coor.row++;
	}
	return (0);
}

static int get_element(t_game *game, char c, t_coor coor, int fruit_num)
{
	t_img img;
	double row;
	double col;
	
	row = coor.row * 32;
	col = coor.col * 32;
	draw_img(game, game->map_img[0], row, col);
	set_pos(game, c, &row, &col);
	if (c == '1')
		img = game->map_img[1];
	else if (c == 'E')
		img = game->map_img[2];
	else if (c == 'P')
	{
		if (coor.col < game->map->width / 2)
			game->cur_dir = 1;
		else
			game->cur_dir = 0;
		img = game->stand[game->cur_dir][0];
	}
	else if (c == 'C')
		img = game->fruit[fruit_num];
	else
		return (0);
	draw_img(game, img, row, col);
	return (0);
}

static void set_pos(t_game *game, char c, double *row, double *col)
{
	if (c == '1')
	{
		*row = *row + game->pos.tree_row;
		*col += game->pos.tree_col;
	}
	else if (c == 'E')
	{
		*row += game->pos.exit;
		*col += game->pos.exit;
	}
	else if (c == 'C')
	{
		*row += game->pos.fruit_row;
		*col += game->pos.fruit_col;
	}
}