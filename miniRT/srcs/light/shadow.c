/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:49:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/23 10:25:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	shadow(t_object *world, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.t_min = EPSILON;
	rec.t_max = light_len;
	return (hit(world, light_ray, &rec, TRUE));
}