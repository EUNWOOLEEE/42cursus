/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/27 12:39:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

static t_bool	cone_hit_side(t_cone *co, t_ray ray, t_hit_record *rec);
static t_bool	cone_hit_plane(t_cone *co, t_ray ray, t_hit_record *rec);

t_cone	*cone(char **strs)
{
	t_cone	*co;

	if (cnt_strs(strs) != 6)
		print_error_exit(USAGE_CO);
	co = (t_cone *)ft_calloc(1, sizeof(t_cone));
	if (!co)
		print_error_exit(MEMORY);\
	if (parse_coor(&(co->center), ft_split(strs[1], ',')) == FALSE \
		|| parse_coor(&(co->dir), ft_split(strs[2], ',')) == FALSE \
		|| parse_double(&co->diameter, strs[3]) == FALSE \
		|| parse_double(&co->h, strs[4]) == FALSE \
		|| parse_color(&(co->color), ft_split(strs[5], ',')) == FALSE \
		|| check_vector(co->dir) == FALSE \
		|| check_color(co->color) == FALSE)
		print_error_exit(USAGE_CO);
	co->radius = co->diameter / 2;
	co->color = color_to_albedo(co->color);
	co->dir = vec_unit(co->dir);
	return (co);
}

int		cone_hit(t_cone *co, t_ray ray, t_hit_record *rec)
{
	int	res;

	res = cone_hit_plane(co, ray, rec);
	res += cone_hit_side(co, ray, rec);
	return (res);
}

static t_bool	cone_hit_side(t_cone *co, t_ray ray, t_hit_record *rec)
{
	double	m = pow(co->radius, 2) / pow(co->h, 2);
	t_vec	h = vec_plus2(co->center, vec_multi(co->dir, co->h));

	t_vec	w = vec_minus2(ray.orig, h);
	double	vh = vec_dot(ray.dir, co->dir);
	double	wh = vec_dot(w, co->dir);

	double	a = vec_len_squared(ray.dir) - m * pow(vh, 2) - pow(vh, 2);
	double	half_b = vec_dot(ray.dir, w) - m * vh * wh - vh * wh;
	double	c = vec_len_squared(w) - m * pow(wh, 2) - pow(wh, 2);

	double	D = pow(half_b, 2) - a * c;
	if (D < 0)
		return (FALSE);
	
	double	t = (-half_b - sqrt(D)) / a;
	if (t < rec->t_min || rec->t_max < t)
	{
		t = (-half_b + sqrt(D)) / a;
		if (t < rec->t_min || rec->t_max < t)
			return (FALSE);
	}

	t_vec	at = ray_at(ray, t);

	t_vec	hp = vec_minus2(at, h);
	double	theta = vec_dot(vec_unit(hp), vec_unit(vec_minus2(co->center, h)));
	t_vec	hq = vec_multi(hp, theta);

	if (vec_len(hq) > co->h || theta < 0)
		return (FALSE);

	rec->t = t;
	rec->p = at;
	rec->n = vec_unit(vec_minus2(at, hq));
	obj_set_face_n(ray, rec);

	rec->color = co->color;
	return (TRUE);
}

static t_bool	cone_hit_plane(t_cone *co, t_ray ray, t_hit_record *rec)
{
	double	pc_len;
	double	t;

	double dot = vec_dot(ray.dir, co->dir);
	t = vec_dot(vec_minus2(co->center, ray.orig), co->dir) / dot;

	t_vec	at = ray_at(ray, t);
	pc_len = vec_len(vec_minus2(co->center, at));
	if (co->radius < fabs(pc_len))
		return (FALSE);
	if (t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->t = t;
	rec->p = at;
	rec->n = vec_unit(co->dir);
	obj_set_face_n(ray, rec);
	rec->color = co->color;
	return (TRUE);
}