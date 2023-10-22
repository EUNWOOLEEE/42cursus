/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:52:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/22 19:54:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	obj_set_rec(t_hit_record *rec)
{
	rec->t = 0;
	rec->t_min = EPSILON;
	rec->t_max = INFINITY;
	rec->front_face = FALSE;
}

void	obj_set_face_n(t_ray r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r.dir, rec->n) < 0;
	rec->n = rec->front_face ? rec->n : vec_multi(rec->n, -1);
}
