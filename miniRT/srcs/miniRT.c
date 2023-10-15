/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:07:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:50:28 by eunwolee         ###   ########.fr       */
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
	t_info	*info;
	
	info = info_init(argc, argv[1]);
	if (!info)
		return (0);
	if (info_read(info) == FALSE)
	{
		close(info->fd);
		free(info);
		return (0);
	}

	img_set(info);
	mlx_set(info);
	img_ptr_set(info);
	cam_set(info);
	
	for(int j = info->img.h - 1; j >= 0; j--)
	{
		for(int i = 0; i < info->img.w; i++)
		{
			double u = (double)i / (double)(info->img.w - 1);
			double v = (double)j / (double)(info->img.h - 1);
			
			t_color rgb = ray_color(ray_first(info, u, v));
			my_mlx_pixel_put(info, i, j, set_color(0, rgb.x * TIMES, rgb.y * TIMES, rgb.z * TIMES));
		}
	}

	img_draw_to_window(info);
	mlx_loop(info->mlx_ptr);
	
	// print_infos(info);
	return (0);
}