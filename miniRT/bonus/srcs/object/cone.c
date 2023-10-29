/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/29 21:16:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_cone			*cone(char **strs);
t_bool			cone_hit(t_cone *co, t_ray ray, t_hit_record *rec);
static t_bool	cone_hit_side(t_cone *co, t_ray ray, t_hit_record *rec);
static t_bool	get_side_n(t_cone *co, t_ray ray, t_hit_record *rec, double t);
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
		|| co->diameter < 0 \
		|| parse_double(&co->h, strs[4]) == FALSE \
		|| co->h < 0 \
		|| parse_color(&(co->color), ft_split(strs[5], ',')) == FALSE \
		|| check_vector(co->dir) == FALSE \
		|| check_color(co->color) == FALSE)
		print_error_exit(USAGE_CO);
	co->radius = co->diameter / 2;
	co->color = color_to_albedo(co->color);
	co->dir = vec_unit(co->dir);
	co->top = vec_plus2(co->center, vec_multi(co->dir, co->h));
	return (co);
}

t_bool		cone_hit(t_cone *co, t_ray ray, t_hit_record *rec)
{
	t_bool	hit;

	hit = FALSE;
	if (cone_hit_plane(co, ray, rec))
	{
		rec->t_max = rec->t;
		hit = TRUE;
	}
	if (cone_hit_side(co, ray, rec))
		hit = TRUE;
	return (hit);
}

static t_bool	cone_hit_side(t_cone *co, t_ray ray, t_hit_record *rec)
{
	t_discriminant	d;
	double	m;
	t_vec	w;
	double	vh;
	double	wh;

	m = pow(co->radius, 2) / pow(co->h, 2);
	w = vec_minus2(ray.orig, co->top);
	vh = vec_dot(ray.dir, co->dir);
	wh = vec_dot(w, co->dir);
	d.a = vec_len_squared(ray.dir) - m * pow(vh, 2) - pow(vh, 2);
	d.half_b = vec_dot(ray.dir, w) - m * vh * wh - vh * wh;
	d.c = vec_len_squared(w) - m * pow(wh, 2) - pow(wh, 2);
	d.D = pow(d.half_b, 2) - d.a * d.c;
	if (d.D < 0 \
		|| check_t_range(rec, &d) == FALSE \
		|| get_side_n(co, ray, rec, d.t) == FALSE)
		return (FALSE);
	rec_set(ray, rec, d.t, co->color);
	return (TRUE);
}

static t_bool	get_side_n(t_cone *co, t_ray ray, t_hit_record *rec, double t)
{
	t_vec	at;
	double	theta;
	t_vec	hp;
	double	hq_len;
	t_vec	hq;

	at = ray_at(ray, t);
	hp = vec_minus2(at, co->top);
	theta = vec_dot(vec_multi(co->dir, -1), vec_unit(hp));
	hq = vec_multi(hp, theta);
	if (vec_len(hq) > co->h || theta < 0)
		return (FALSE);
	hq_len = vec_len(hp) / theta;
	hq = vec_plus2(co->top, vec_multi(vec_multi(co->dir, -1), hq_len));
	rec->n = vec_unit(vec_minus2(at, hq));
	return (TRUE);
}

static t_bool	cone_hit_plane(t_cone *co, t_ray ray, t_hit_record *rec)
{
	double	t;
	double	pc_len;

	t = vec_dot(vec_minus2(co->center, ray.orig), co->dir) / vec_dot(ray.dir, co->dir);
	pc_len = vec_len(vec_minus2(co->center, ray_at(ray, t)));
	if (co->radius < fabs(pc_len) \
		|| t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->n = vec_unit(co->dir);
	rec_set(ray, rec, t, co->color);
	return (TRUE);
}
