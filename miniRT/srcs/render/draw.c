/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:49:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 15:22:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char *tmp;

	tmp = scene->img.addr + y * scene->img.size_line + x * (scene->img.bits_per_pixel / 8);
	*(unsigned int *)tmp = color;
}

void	img_draw_to_window(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr, scene->img.ptr, 0, 0);
}