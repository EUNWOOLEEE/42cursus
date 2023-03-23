/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:30:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/23 16:37:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int get_element(t_vars *vars, char c, t_coor *coor, int fruit_num);

int draw_map(t_map *map, t_vars *vars)
{
	int fruit_num;
	t_coor *coor;

	fruit_num = 0;
	coor = (t_coor *)ft_calloc(1, sizeof(t_coor));
	if (!coor)
		return (-1);
	coor->row = 0;
	while (coor->row < map->height)
	{
		coor->col = 0;
		while (coor->col < map->width)
		{
			if (get_element(vars, map->map[coor->row][coor->col], coor, fruit_num) == -1)
				return (free_n_print_out(2, 0, coor, 0));
			if (map->map[coor->row][coor->col] == 'C')
				fruit_num = (fruit_num + 1) % 5;
			coor->col++;
		}
		coor->row++;
	}
	return (free_n_print_out(1, 0, coor, 0));
}

int put_element(t_vars *vars, char *name, double row, double col)
{
	t_img *img;

	img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!img)
		return (-1);
	img->img = mlx_png_file_to_image(vars->mlx, name, &img->img_width, &img->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, col, row);
	return (free_n_print_out(1, 0, img, 0));
}

static int get_element(t_vars *vars, char c, t_coor *coor, int fruit_num)
{
	int res;
	char *fruits;

	res = 0;
	fruits = ft_strdup("textures/fruits/0.png");
	if (!fruits)
		return (-1);
	if (put_element(vars, "textures/map/grass.png", coor->row * 32, coor->col * 32) == -1)
		return (free_n_print_out(2, 0, fruits, 0));
	if (c == '1')
		res = put_element(vars, "textures/map/tree.png", (coor->row * 32) + (32 * 0.065), (coor->col * 32) + (32 * 0.06));
	else if (c == 'E')
		res = put_element(vars, "textures/map/exit.png", (coor->row * 32) + (32 * 0.15), (coor->col * 32) + (32 * 0.15));
	else if (c == 'P')
		res = put_element(vars, "textures/standing/standing1-0.png", (coor->row * 32) + (32 * 0.25), (coor->col * 32) + (32 * 0.2));
	else if (c == 'C')
	{
		fruits[16] = fruit_num + '0';
		res = put_element(vars, fruits, (coor->row * 32) + (32 * 0.25), (coor->col * 32) + (32 * 0.22));
	}
	if (res == -1)
		return (free_n_print_out(2, 0, fruits, 0));
	return (free_n_print_out(1, 0, fruits, 0));
}