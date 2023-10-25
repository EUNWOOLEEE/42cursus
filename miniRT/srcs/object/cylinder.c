/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:16:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/25 10:11:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_cylinder	*cylinder(char **strs)
{
	t_cylinder	*cy;
	
	if (cnt_strs(strs) != 6)
		print_error_exit(USAGE_CY);
	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		print_error_exit(MEMORY);
	parse_coor(&(cy->center), ft_split(strs[1], ','));
	parse_coor(&(cy->dir), ft_split(strs[2], ','));
	cy->diameter = ft_atod(strs[3]);
	cy->radius = cy->diameter / 2;
	cy->radius_squared = cy->radius * cy->radius;
	cy->h = ft_atod(strs[4]);
	parse_color(&(cy->color), ft_split(strs[5], ','));
	if (check_vector(cy->dir) == FALSE ||
		check_color(cy->color) == FALSE)
		print_error_exit(USAGE_CY);
	cy->color = color_to_albedo(cy->color);
	return (cy);
}

t_bool	cylinder_hit(t_cylinder *cy, t_ray ray, t_hit_record *rec)
{
	double	a;
	double	b;
	double	c;
	double	D;
	double	t;

	t_vec	cl;
	t_vec	h;
	t_vec	h_unit;

	cl = vec_minus2(ray.orig, cy->center); // 원기둥의 중심 -> 카메라
	h = vec_plus2(vec_multi(cy->dir, cy->h), cy->center); // 원기둥의 중심 축
	h_unit = vec_unit(h);
	
	double	vh = vec_dot(ray.dir, h_unit);
	double	wh = vec_dot(cl, h_unit);
	
	a = vec_len_squared(ray.dir) - vh * vh;
	b = 2 * (vec_dot(ray.dir, cl) - vh * wh);
	c = vec_len_squared(cl) - wh * wh - cy->radius_squared;
	D = b * b - 4 * a * c;
	if (D < 0)
		return (FALSE);
		
	t = (-b - sqrt(D)) / (2 * a);
	if (t < rec->t_min || rec->t_max < t)
	{
		t = (-b + sqrt(D)) / (2 * a);
		if (t < rec->t_min || rec->t_max < t)
			return (FALSE);
	}

	t_vec	at = ray_at(ray, t);
	t_vec	cp = vec_minus2(at, cy->center);
	double	hit_h = vec_dot(cp, cy->dir);

	// printf("hit_h: %lf h_len: %lf\n", hit_h, vec_len(h));
	if (hit_h < 0 || cy->h < hit_h)
		return (FALSE);

	rec->p = at;
	rec->t = t;
	rec->color = cy->color;

	t_vec	cq = vec_multi(vec_plus2(cy->center, cy->dir), hit_h);
	rec->n = vec_unit(vec_minus2(rec->p, cq));
	obj_set_face_n(ray, rec);
	return (TRUE);
}

t_bool	cylinder_hit_plane(t_cylinder *cy, t_ray ray, t_hit_record *rec, t_bool top)
{
	double	pc_len;
	double	t;
	t_vec	center;

	double dot = vec_dot(ray.dir, cy->dir);
	if (top)
		center = vec_plus2(vec_multi(cy->dir, cy->h), cy->center);
	else
		center = cy->center;
	t = vec_dot(vec_minus2(center, ray.orig), cy->dir) / dot;

	t_vec	at = ray_at(ray, t);
	pc_len = vec_len(vec_minus2(center, at));
	if (cy->radius < fabs(pc_len))
		return (FALSE);
	if (t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->t = t;
	rec->p = at;
	if (top)
		rec->n = cy->dir;
	else
		rec->n = vec_multi(cy->dir, -1);
	// obj_set_face_n(ray, rec);
	rec->color = cy->color;
	return (TRUE);
}