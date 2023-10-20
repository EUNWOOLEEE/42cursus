/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:51 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 17:13:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	vec_dot(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x \
			+ vec1.y * vec2.y \
			+ vec1.z * vec2.z);
}

t_vec	vec_cross(t_vec vec1, t_vec vec2)
{
	t_vec	tmp;

	tmp.x = (vec1.y * vec2.z - vec1.z * vec2.y);
	tmp.y = (vec1.z * vec2.x - vec1.x * vec2.z);
	tmp.z = (vec1.x * vec2.y - vec1.y * vec2.x);
	return (tmp);
}