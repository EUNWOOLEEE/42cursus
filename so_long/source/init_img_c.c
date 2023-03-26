/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 17:53:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int stand_img(t_game *game)
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

int walk_img(t_game *game)
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

int jump_img(t_game *game)
{
	t_coor coor;
	char *jump;

	coor.row = 0;
	jump = ft_strdup("textures/jump/jump0-00.png");
	if (!jump)
		return (-1);
	while (coor.row < 2)
	{
		coor.col = 0;
		jump[18] = coor.row + '0';
		jump[20] = '0';
		while (coor.col < 11)
		{
			if (coor.col == 10)
				jump[20] = '1';
			jump[21] = (coor.col % 10) + '0';
			game->jump[coor.row][coor.col].img_ptr = mlx_png_file_to_image(game->mlx, jump, 
				&game->jump[coor.row][coor.col].width, &game->jump[coor.row][coor.col].height);
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, jump, 0));
}

int rest_img(t_game *game)
{
	t_coor coor;
	char *rest;

	coor.row = 0;
	rest = ft_strdup("textures/rest/rest0-00.png");
	if (!rest)
		return (-1);
	while (coor.row < 2)
	{
		coor.col = 0;
		rest[18] = coor.row + '0';
		rest[20] = '0';
		while (coor.col < 14)
		{
			if (coor.col == 10)
				rest[20] = '1';
			rest[21] = (coor.col % 10) + '0';
			game->rest[coor.row][coor.col].img_ptr = mlx_png_file_to_image(game->mlx, rest, 
				&game->rest[coor.row][coor.col].width, &game->rest[coor.row][coor.col].height);
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, rest, 0));
}

int sleep_img(t_game *game)
{
	t_coor coor;
	char *sleep;

	coor.row = 0;
	sleep = ft_strdup("textures/sleep/sleep0-0.png");
	if (!sleep)
		return (-1);
	while (coor.row < 2)
	{
		coor.col = 0;
		sleep[20] = coor.row + '0';
		while (coor.col < 6)
		{
			sleep[22] = coor.col + '0';
			game->sleep[coor.row][coor.col].img_ptr = mlx_png_file_to_image(game->mlx, sleep, 
				&game->sleep[coor.row][coor.col].width, &game->sleep[coor.row][coor.col].height);
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, sleep, 0));
}