/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:02:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:26:42 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_point	ray_at(t_ray ray, double t)
{
	t_point	at;

	at = vec_n_vec_cal(ray.orig, vec_cal(ray.dir, t, '*'), '+');
	return (at);
}

t_ray	ray_first(t_info *info, double u, double v)
{
	t_ray	r;

	r.orig = info->cam.orig;
	t_vec tmp1 = vec_cal(info->cam.horizontal, u, '*');
	t_vec tmp2 = vec_cal(info->cam.vertical, v, '*');
	r.dir = vec_n_vec_cal(info->cam.lower_left_corner, tmp1, '+');
	r.dir = vec_n_vec_cal(r.dir, tmp2, '+');
	r.dir = vec_n_vec_cal(r.dir, r.orig, '-');
	return (r);
}

t_color ray_color(t_ray r)
{
	t_color	res;
	t_color	tmp1;
	t_color	tmp2;

	t_vec	unit_dir = vec_unit(r.dir);
	double	t = 0.5 * (1.0 - unit_dir.y);
	rgb_set(&tmp1, 1.0, 1.0, 1.0);
	tmp1 = rgb_cal(tmp1, (1.0 - t), '*');
	rgb_set(&tmp2, 0.5, 0.7, 1.0);
	tmp2 = rgb_cal(tmp2, t, '*');
	res = rgb_n_rgb_cal(tmp1, tmp2, '+');
	return (res);
}
