/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:30:56 by eunwolee          #+#    #+#             */
/*   Updated: 2024/08/31 14:46:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void		draw_img(t_game *game, t_img img, double row, double col);
int			draw_map(t_game *game);
static int	get_element(t_game *game, char c, t_coor coor, int fruit_num);
static void	set_distance(t_game *game);
static void	set_position(t_game *game, char c, double *row, double *col);

void	draw_img(t_game *game, t_img img, double row, double col)
{
	mlx_put_image_to_window(game->mlx, game->win, img.img_ptr, col, row);
}

int	draw_map(t_game *game)
{
	int		fruit_num;
	t_coor	coor;

	fruit_num = 0;
	coor.row = 0;
	set_distance(game);
	while (coor.row < game->map.height)
	{
		coor.col = 0;
		while (coor.col < game->map.width)
		{
			get_element
				(game, game->map.map[coor.row][coor.col], coor, fruit_num);
			if (game->map.map[coor.row][coor.col] == 'C')
				fruit_num = (fruit_num + 1) % 5;
			coor.col++;
		}
		coor.row++;
	}
	return (0);
}

static int	get_element(t_game *game, char c, t_coor coor, int fruit_num)
{
	t_img	img;
	double	row;
	double	col;

	row = coor.row * SPRITE_SIZE;
	col = coor.col * SPRITE_SIZE;
	draw_img(game, game->map_img[0], row, col);
	set_position(game, c, &row, &col);
	if (c == '1')
		img = game->map_img[1];
	else if (c == 'E')
		img = game->map_img[2];
	else if (c == 'C')
		img = game->fruit[fruit_num];
	else if (c == 'H')
		img = game->map_img[3];
	else
		return (0);
	draw_img(game, img, row, col);
	return (0);
}

static void	set_distance(t_game *game)
{
	game->dis.tree_row = 32 * 0.065;
	game->dis.tree_col = 32 * 0.06;
	game->dis.fruit_row = 32 * 0.25;
	game->dis.fruit_col = 32 * 0.22;
	game->dis.hole_row = 32 * 0.33;
	game->dis.hole_col = 32 * 0.05;
	game->dis.exit = 32 * 0.17;
}

static void	set_position(t_game *game, char c, double *row, double *col)
{
	if (c == '1')
	{
		*row = *row + game->dis.tree_row;
		*col += game->dis.tree_col;
	}
	else if (c == 'E')
	{
		*row += game->dis.exit;
		*col += game->dis.exit;
	}
	else if (c == 'C')
	{
		*row += game->dis.fruit_row;
		*col += game->dis.fruit_col;
	}
	else if (c == 'H')
	{
		*row += game->dis.hole_row;
		*col += game->dis.hole_col;
	}
}
