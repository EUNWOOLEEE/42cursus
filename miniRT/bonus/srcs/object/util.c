/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:52:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 13:25:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	rec_init(t_hit_record *rec);
void	rec_set(t_ray ray, t_hit_record *rec, double t, t_color color);
void	set_face_n(t_ray r, t_hit_record *rec);
t_bool	check_t_range(t_hit_record *rec, t_discriminant *d);

void	rec_init(t_hit_record *rec)
{
	rec->t = 0;
	rec->t_min = EPSILON;
	rec->t_max = INFINITY;
	rec->front_face = FALSE;
}

void	rec_set(t_ray ray, t_hit_record *rec, double t, t_color color)
{
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->color = color;
	set_face_n(ray, rec);
}

void	set_face_n(t_ray r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r.dir, rec->n) < 0;
	if (rec->front_face == FALSE)
		rec->n = vec_multi(rec->n, -1);
}

t_bool	check_t_range(t_hit_record *rec, t_discriminant *d)
{
	d->t = (-d->half_b - sqrt(d->d)) / d->a;
	if (d->t < rec->t_min || rec->t_max < d->t)
	{
		d->t = (-d->half_b + sqrt(d->d)) / d->a;
		if (d->t < rec->t_min || rec->t_max < d->t)
			return (FALSE);
	}
	return (TRUE);
}
