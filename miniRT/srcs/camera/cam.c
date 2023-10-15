/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:19:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	cam_set(t_info *info)
{
	t_vec	tmp;
	double	theta;
	double	h;

	theta = degrees_to_radians(info);
	h = tan(theta / 2);
	info->cam.viewport_h = 2.0 * h;
	info->cam.viewport_w = info->img.aspect_ratio * info->cam.viewport_h;
	info->cam.focal_len = 1.0;
	info->cam.orig = vec_set(0, 0, 0);
	info->cam.horizontal = vec_set(info->cam.viewport_w, 0, 0);
	info->cam.vertical = vec_set(0, info->cam.viewport_h, 0);

	//get LFC
	info->cam.lower_left_corner = vec_n_vec_cal(info->cam.orig, vec_cal(info->cam.horizontal, 2, '/'), '-');
	info->cam.lower_left_corner = vec_n_vec_cal(info->cam.lower_left_corner, vec_cal(info->cam.vertical, 2, '/'), '-');
	tmp = vec_set(0, 0, info->cam.focal_len);
	info->cam.lower_left_corner = vec_n_vec_cal(info->cam.lower_left_corner, tmp, '-');
}
