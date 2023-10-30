/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/29 21:18:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	vec_plus(t_vec vec, double t);
t_vec	vec_minus(t_vec vec, double t);
t_vec	vec_multi(t_vec vec, double t);
t_vec	vec_divide(t_vec vec, double t);

t_vec	vec_plus(t_vec vec, double t)
{
	vec.x += t;
	vec.y += t;
	vec.z += t;
	return (vec);
}

t_vec	vec_minus(t_vec vec, double t)
{
	vec.x -= t;
	vec.y -= t;
	vec.z -= t;
	return (vec);
}

t_vec	vec_multi(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec	vec_divide(t_vec vec, double t)
{
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
