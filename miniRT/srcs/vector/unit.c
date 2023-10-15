/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:42:51 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 21:49:56 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	vec_len_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_len(t_vec vec)
{
	return (sqrt(vec_len_squared(vec)));
}

t_vec	vec_unit(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return vec;
}
