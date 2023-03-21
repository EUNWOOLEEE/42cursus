/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:47:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/21 15:00:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mac/mlx.h"
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

void my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *tmp;

	tmp = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
}

// int key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int mouse_hook(int button, int x, int y, t_vars *vars)
// {
// 	printf("Hello from mouse_hook!\n");
// 	return (0);
// }

int main()
{
	t_data img;
	t_vars vars;
	int img_width;
	int img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");

	img.img = mlx_png_file_to_image(vars.mlx, "imgs/wall.png", &img_width, &img_height);
	for(int i=0; i/32 < 4; i += 32)
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, i, 0);

	img.img = mlx_png_file_to_image(vars.mlx, "imgs/grass2.png", &img_width, &img_height);
	for (int i=0; i/32<4; i+=32)
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, i, 32);

	img.img = mlx_png_file_to_image(vars.mlx, "imgs/stone2.png", &img_width, &img_height);
	for (int i=0; i/32<4; i+=32)
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, i, 64);

	img.img = mlx_png_file_to_image(vars.mlx, "imgs/water2.png", &img_width, &img_height);
	for (int i=0; i/32<4; i+=32)
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, i, 96);

	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}