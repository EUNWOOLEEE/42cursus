/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:49:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 08:14:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char *tmp;

	tmp = info->img.addr + y * info->img.size_line + x * (info->img.bits_per_pixel / 8);
	*(unsigned int *)tmp = color;
}

void	img_draw_to_window(t_info *info)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
}