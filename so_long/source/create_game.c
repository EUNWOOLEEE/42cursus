/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:22:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/21 22:31:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int draw_map(t_map *map, t_vars *vars, t_img *img);

int start_mlx(t_map *map)
{
	t_vars *vars;
	t_img *img;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!vars || !img)
		return (free_n_print_out(2, 0, vars, img));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map->width * 32, map->height * 32, "so_long");
	draw_map(map, vars, img);
	return (0);
}

int draw_map(t_map *map, t_vars *vars, t_img *img)
{
	t_coor coor;

	coor.row = 0;
	while (coor.row < map->height)
	{
		coor.col = 0;
		while (coor.col < map->width)
		{
			if (map->map[coor.row][coor.col] == '1')
			{
				img->img = mlx_png_file_to_image(vars->mlx, "textures/wall.png", &img->img_width, &img->img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, coor.col * 32, coor.row * 32);
			}
			else if (map->map[coor.row][coor.col] == '2')
			{
				// img->img = mlx_png_file_to_image(vars->mlx, "textures/grass2.png", &img->img_width, &img->img_height);
				// mlx_put_image_to_window(vars->mlx, vars->win, img->img, coor.col * 32, coor.row * 32);
				img->img = mlx_png_file_to_image(vars->mlx, "textures/water_copy.png", &img->img_width, &img->img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, coor.col * 32, coor.row * 32);
			}
			else
			{
				img->img = mlx_png_file_to_image(vars->mlx, "textures/grass2.png", &img->img_width, &img->img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, coor.col * 32, coor.row * 32);
			}
			coor.col++;
		}
		coor.row++;
	}
	mlx_loop(vars->mlx);
	return (0);
}