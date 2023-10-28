/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 16:27:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	vec_unit(t_vec vec);
double	vec_len(t_vec vec);
double	vec_len_squared(t_vec vec);

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

double	vec_len(t_vec vec)
{
	return (sqrt(vec_len_squared(vec)));
}

double	vec_len_squared(t_vec vec)
{
	return (vec.x * vec.x \
			+ vec.y * vec.y \
			+ vec.z * vec.z);
}
