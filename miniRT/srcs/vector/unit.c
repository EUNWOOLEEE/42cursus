/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/19 21:21:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	vec_len_squared(t_vec vec)
{
	return (vec.x * vec.x \
			+ vec.y * vec.y \
			+ vec.z * vec.z);
}

double	vec_len(t_vec vec)
{
	return (sqrt(vec_len_squared(vec)));
}

t_vec	vec_unit(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	if (len == 0)
	{
		printf("Divider is 0\n");
		return (vec);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}