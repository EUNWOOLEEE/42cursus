/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:27:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:43:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	img_set(t_info *info)
{
	info->img.aspect_ratio = 16.0 / 9.0;
	info->img.h = 600;
	info->img.w = info->img.h * info->img.aspect_ratio;
}

void	img_ptr_set(t_info *info)
{
	info->img.ptr = mlx_new_image(info->mlx_ptr, info->img.w, info->img.h);
	info->img.addr = mlx_get_data_addr(info->img.ptr, \
					&info->img.bits_per_pixel, \
					&info->img.size_line, \
					&info->img.endian);
}