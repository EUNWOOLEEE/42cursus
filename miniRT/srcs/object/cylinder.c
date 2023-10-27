/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:16:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/27 12:53:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

static t_bool	cylinder_hit_side(t_cylinder *cy, t_ray ray, t_hit_record *rec);
static t_bool	cylinder_hit_plane(t_cylinder *cy, t_ray ray, t_hit_record *rec, double h);

t_cylinder	*cylinder(char **strs)
{
	t_cylinder	*cy;
	
	if (cnt_strs(strs) != 6)
		print_error_exit(USAGE_CY);
	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		print_error_exit(MEMORY);
	if (parse_coor(&(cy->center), ft_split(strs[1], ',')) == FALSE \
		|| parse_coor(&(cy->dir), ft_split(strs[2], ',')) == FALSE \
		|| parse_double(&cy->diameter, strs[3]) == FALSE \
		|| parse_double(&cy->h, strs[4]) == FALSE \
		|| parse_color(&(cy->color), ft_split(strs[5], ',')) == FALSE \
		|| check_vector(cy->dir) == FALSE \
		|| check_color(cy->color) == FALSE)
		print_error_exit(USAGE_CY);
	cy->radius = cy->diameter / 2;
	cy->color = color_to_albedo(cy->color);
	cy->dir = vec_unit(cy->dir);
	return (cy);
}

int		cylinder_hit(t_cylinder *cy, t_ray ray, t_hit_record *rec)
{
	int	res;

	res = cylinder_hit_plane(cy, ray, rec, cy->h / 2);
	res += cylinder_hit_plane(cy, ray, rec, -(cy->h / 2));
	res += cylinder_hit_side(cy, ray, rec);
	return (res);
}

static t_bool	cylinder_hit_side(t_cylinder *cy, t_ray ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	D;
	double	t;

	t_vec	cl;

	cl = vec_minus2(ray.orig, cy->center); // 원기둥의 중심 -> 카메라

	double	vh = vec_dot(ray.dir, cy->dir);
	double	wh = vec_dot(cl, cy->dir);
	
	a = vec_len_squared(ray.dir) - vh * vh;
	half_b = vec_dot(ray.dir, cl) - vh * wh;
	c = vec_len_squared(cl) - wh * wh - pow(cy->radius, 2);
	D = pow(half_b, 2) - a * c;
	if (D < 0)
		return (FALSE);
		
	t = (-half_b - sqrt(D)) / a;
	if (t < rec->t_min || rec->t_max < t)
	{
		t = (-half_b + sqrt(D)) / a;
		if (t < rec->t_min || rec->t_max < t)
			return (FALSE);
	}

	t_vec	at = ray_at(ray, t);
	t_vec	cp = vec_minus2(at, cy->center);
	double	hit_h = sqrt(vec_len_squared(cp) - pow(cy->radius, 2.0));

	if (cy->h / 2 < hit_h)
		return (FALSE);

	rec->p = at;
	rec->t = t;
	rec->color = cy->color;


	t_vec	cq;
	if (vec_dot(cy->dir, vec_unit(cp)) >= 0)
		cq = vec_plus2(cy->center, vec_multi(cy->dir, hit_h));
	else
		cq = vec_plus2(cy->center, vec_multi(cy->dir, -hit_h));

	rec->n = vec_unit(vec_minus2(rec->p, cq));
	obj_set_face_n(ray, rec);
	return (TRUE);
}

static t_bool	cylinder_hit_plane(t_cylinder *cy, t_ray ray, t_hit_record *rec, double h)
{
	double	pc_len;
	double	t;
	t_vec	center;

	double dot = vec_dot(ray.dir, cy->dir);
	center = vec_plus2(cy->center, vec_multi(cy->dir, h)); // 원평면의 중심
	t = vec_dot(vec_minus2(center, ray.orig), cy->dir) / dot;

	t_vec	at = ray_at(ray, t);
	pc_len = vec_len(vec_minus2(center, at));
	if (cy->radius < fabs(pc_len))
		return (FALSE);
	if (t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->t = t;
	rec->p = at;
	if (0 < h)
		rec->n = vec_unit(cy->dir);
	else
		rec->n = vec_multi(vec_unit(cy->dir), -1);
	obj_set_face_n(ray, rec);
	rec->color = cy->color;
	return (TRUE);
}