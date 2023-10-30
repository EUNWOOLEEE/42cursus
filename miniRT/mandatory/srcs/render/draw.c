/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:49:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 13:04:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void		draw_loop(t_scene *scene);
static void	draw(t_scene *scene, int i, int j, int k);
static void	draw_mlx_pixel_put(t_scene *scene, int x, int y, int color);
static void	draw_img_to_window(t_scene *scene);

void	draw_loop(t_scene *scene)
{
	int		i;
	int		j;
	int		k;

	j = -1;
	k = scene->img.h - 1;
	while (++j < scene->img.h - 1)
	{
		i = -1;
		while (++i < scene->img.w)
			draw(scene, i, j, k);
		k--;
	}
	draw_img_to_window(scene);
}

static void	draw(t_scene *scene, int i, int j, int k)
{
	double	u;
	double	v;
	t_color	color;

	u = (double)i / (scene->img.w - 1);
	v = (double)k / (scene->img.h - 1);
	scene->ray = ray_first(scene, u, v);
	color = ray_color(scene);
	draw_mlx_pixel_put(scene, i, j, \
		color_to_int(0, color.x * TIMES, color.y * TIMES, color.z * TIMES));
}

static void	draw_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*tmp;

	tmp = scene->img.addr \
			+ y * scene->img.size_line \
			+ x * (scene->img.bits_per_pixel / 8);
	*(unsigned int *)tmp = color;
}

static void	draw_img_to_window(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx_ptr, \
								scene->win_ptr, scene->img.ptr, 0, 0);
}
