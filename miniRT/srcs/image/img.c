/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:37:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/23 08:50:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	img_set(t_scene *scene)
{
	scene->img.aspect_ratio = 16.0 / 9.0;
	scene->img.h = 600;
	scene->img.w = scene->img.h * scene->img.aspect_ratio;
}

void	img_ptr_set(t_scene *scene)
{
	scene->img.ptr = mlx_new_image(scene->mlx_ptr, scene->img.w, scene->img.h);
	scene->img.addr = mlx_get_data_addr(scene->img.ptr, \
		&scene->img.bits_per_pixel, &scene->img.size_line, &scene->img.endian);
}