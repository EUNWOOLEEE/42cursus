/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:47:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/20 17:30:00 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

// void my_mlx_pixel_put(t_data *img, int x, int y, int color)
// {
// 	char *tmp;

// 	tmp = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)tmp = color;
// }

int key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Hello from mouse_hook!\n");
	return (0);
}

int main()
{
	// void *mlx;
	// void *mlx_win;
	// t_data img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);

	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);

	mlx_loop_hook()
}