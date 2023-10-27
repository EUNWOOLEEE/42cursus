/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:07:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/27 08:38:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

double	clamp(double x, double min, double max)
{
	if(x < min) return min;
	if(x > max) return max;
	return x;
}

int main(int argc, char **argv)
{
	debug = 0;
	t_scene	*scene;
	
	scene = scene_init(argc, argv[1]);
	scene_read(scene);

	img_set(scene);
	cam_set(scene);
	mlx_set(scene);
	img_ptr_set(scene);

	for(int j = 0, k = scene->img.h - 1; j < scene->img.h - 1; j++, k--)
	{
		for(int i = 0; i < scene->img.w; i++)
		{
			double u = (double)i / (scene->img.w - 1);
			double v = (double)k / (scene->img.h - 1);
			
			scene->ray = ray_first(scene, u, v);
			t_color	color = ray_color(scene);
			
			my_mlx_pixel_put(scene, i, j, \
				color_to_int(0, color.x * TIMES, color.y * TIMES, color.z * TIMES));
		}
	}

	img_draw_to_window(scene);
	mlx_loop(scene->mlx_ptr);
	return (0);
}