/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:44:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stand_img(t_game *game, char *str)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < 2)
	{
		coor.col = 0;
		str[20] = coor.row + '0';
		while (coor.col < 5)
		{
			str[22] = coor.col + '0';
			game->stand[coor.row][coor.col].img_ptr = mlx_png_file_to_image
				(game->mlx, str, &game->stand[coor.row][coor.col].width,
					&game->stand[coor.row][coor.col].height);
			if (!game->stand[coor.row][coor.col].img_ptr)
				return (free_n_print_out(2, 0, str, 0));
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, str, 0));
}

int	walk_img(t_game *game, char *str)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < 2)
	{
		coor.col = 0;
		str[18] = coor.row + '0';
		while (coor.col < 8)
		{
			str[20] = coor.col + '0';
			game->walk[coor.row][coor.col].img_ptr = mlx_png_file_to_image
				(game->mlx, str, &game->walk[coor.row][coor.col].width,
					&game->walk[coor.row][coor.col].height);
			if (!game->walk[coor.row][coor.col].img_ptr)
				return (free_n_print_out(2, 0, str, 0));
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, str, 0));
}

int	jump_img(t_game *game, char *str)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < 2)
	{
		coor.col = 0;
		str[18] = coor.row + '0';
		str[20] = '0';
		while (coor.col < 11)
		{
			if (coor.col == 10)
				str[20] = '1';
			str[21] = (coor.col % 10) + '0';
			game->jump[coor.row][coor.col].img_ptr = mlx_png_file_to_image
				(game->mlx, str, &game->jump[coor.row][coor.col].width,
					&game->jump[coor.row][coor.col].height);
			if (!game->jump[coor.row][coor.col].img_ptr)
				return (free_n_print_out(2, 0, str, 0));
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, str, 0));
}

int	rest_img(t_game *game, char *str)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < 2)
	{
		coor.col = 0;
		str[18] = coor.row + '0';
		str[20] = '0';
		while (coor.col < 14)
		{
			if (coor.col == 10)
				str[20] = '1';
			str[21] = (coor.col % 10) + '0';
			game->rest[coor.row][coor.col].img_ptr = mlx_png_file_to_image
				(game->mlx, str, &game->rest[coor.row][coor.col].width,
					&game->rest[coor.row][coor.col].height);
			if (!game->rest[coor.row][coor.col].img_ptr)
				return (free_n_print_out(2, 0, str, 0));
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, str, 0));
}

int	sleep_img(t_game *game, char *str)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < 2)
	{
		coor.col = 0;
		str[20] = coor.row + '0';
		while (coor.col < 6)
		{
			str[22] = coor.col + '0';
			game->sleep[coor.row][coor.col].img_ptr = mlx_png_file_to_image
				(game->mlx, str, &game->sleep[coor.row][coor.col].width,
					&game->sleep[coor.row][coor.col].height);
			if (!game->sleep[coor.row][coor.col].img_ptr)
				return (free_n_print_out(2, 0, str, 0));
			coor.col++;
		}
		coor.row++;
	}
	return (free_n_print_out(1, 0, str, 0));
}
