/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:10:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:09:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int map_fruit_img(t_game *game);
static int stand_img(t_game *game);
static int walk_img(t_game *game);
static int jump_img(t_game *game);

int img_init(t_game *game)
{
	map_fruit_img(game);
	stand_img(game);
	walk_img(game);
	jump_img(game);

	game->pos.tree_row = 32 * 0.065;
	game->pos.tree_col = 32 * 0.06;
	game->pos.exit = 32 * 0.15;
	game->pos.fox_row = 32 * 0.25;
	game->pos.fox_col = 32 * 0.2;
	game->pos.fruit_row = 32 * 0.25;
	game->pos.fruit_col = 32 * 0.22;
	game->dis = 4;
	return (0);
}

static int map_fruit_img(t_game *game)
{
	int num;
	char *fruit;

	num = 0;
	fruit = ft_strdup("textures/fruits/0.png");
	if (!fruit)
		return (-1);
	game->map_img[0].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/grass.png", &game->map_img[0].width, &game->map_img[0].height);
	game->map_img[1].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/tree.png", &game->map_img[1].width, &game->map_img[1].height);
	game->map_img[2].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/exit.png", &game->map_img[2].width, &game->map_img[2].height);
	while (num < 5)
	{
		fruit[16] = num + '0';
		game->fruit[num].img_ptr = mlx_png_file_to_image
		(game->mlx, fruit, &game->fruit[num].width, &game->fruit[num].height);
		num++;
	}
	return (free_n_print_out(1, 0, fruit, 0));
}

static int stand_img(t_game *game)
{
	t_coor coor;
	char *stand;

	coor.row = 0;
	stand = ft_strdup("textures/stand/stand0-0.png");
	if (!stand)
		return (-1);
	while (coor.row < 2)
	{
		coor.col = 0;
		stand[20] = coor.row + '0';
		while (coor.col < 5)
		{
			stand[22] = coor.col + '0';
			game->stand[coor.row][coor.col].img_ptr = mlx_png_file_to_image(game->mlx, stand, 
				&game->stand[coor.row][coor.col].width, &game->stand[coor.row][coor.col].height);
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, stand, 0));
}

static int walk_img(t_game *game)
{
	t_coor coor;
	char *walk;

	coor.row = 0;
	walk = ft_strdup("textures/walk/walk0-0.png");
	if (!walk)
		return (-1);
	while (coor.row < 2)
	{
		coor.col = 0;
		walk[18] = coor.row + '0';
		while (coor.col < 8)
		{
			walk[20] = coor.col + '0';
			game->walk[coor.row][coor.col].img_ptr = mlx_png_file_to_image(game->mlx, walk, 
				&game->walk[coor.row][coor.col].width, &game->walk[coor.row][coor.col].height);
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, walk, 0));
}

static int jump_img(t_game *game)
{
	int num;
	char *jump;

	num = 0;
	jump = ft_strdup("textures/jump/jump0.png");
	if (!jump)
		return (-1);
	game->map_img[0].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/grass.png", &game->map_img[0].width, &game->map_img[0].height);
	game->map_img[1].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/tree.png", &game->map_img[1].width, &game->map_img[1].height);
	game->map_img[2].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/exit.png", &game->map_img[2].width, &game->map_img[2].height);
	while (num < 5)
	{
		jump[18] = num + '0';
		game->jump[num].img_ptr = mlx_png_file_to_image
		(game->mlx, jump, &game->jump[num].width, &game->jump[num].height);
		num++;
	}
	return (free_n_print_out(1, 0, jump, 0));
}