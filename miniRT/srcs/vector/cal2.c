/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/29 21:18:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	vec_plus2(t_vec vec1, t_vec vec2);
t_vec	vec_minus2(t_vec vec1, t_vec vec2);
t_vec	vec_multi2(t_vec vec1, t_vec vec2);
t_vec	vec_divide2(t_vec vec1, t_vec vec2);

t_vec	vec_plus2(t_vec vec1, t_vec vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

t_vec	vec_minus2(t_vec vec1, t_vec vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

t_vec	vec_multi2(t_vec vec1, t_vec vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}

t_vec	vec_divide2(t_vec vec1, t_vec vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	vec1.z /= vec2.z;
	return (vec1);
}
