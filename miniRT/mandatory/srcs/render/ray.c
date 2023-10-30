/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 14:30:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_point	ray_at(t_ray ray, double t);
t_ray	ray_first(t_scene *scene, double u, double v);
t_color	ray_color(t_scene *scene);

t_point	ray_at(t_ray ray, double t)
{
	t_point	at;

	at = vec_plus2(ray.orig, vec_multi(ray.dir, t));
	return (at);
}

t_ray	ray_first(t_scene *scene, double u, double v)
{
	t_ray	r;

	r.orig = scene->cam.orig;
	r.dir = vec_plus2(scene->cam.llc, vec_multi(scene->cam.horizontal, u));
	r.dir = vec_plus2(r.dir, vec_multi(scene->cam.vertical, v));
	r.dir = vec_minus2(r.dir, r.orig);
	return (r);
}

t_color	ray_color(t_scene *scene)
{
	rec_init(&scene->rec);
	if (hit(scene->world, scene->ray, &scene->rec))
		return (light_phong(scene));
	return (color(0, 0, 0));
}
