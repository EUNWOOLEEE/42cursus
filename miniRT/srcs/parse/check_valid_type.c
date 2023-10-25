/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:28:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/25 11:14:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
		return (FALSE);
	return (TRUE);
}

t_bool	check_color(t_color color)
{
	if (color.x < 0 || 255 < color.x \
		|| color.y < 0 || 255 < color.y \
		|| color.z < 0 || 255 < color.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_vector(t_vec vector)
{
	if (vector.x < -1 || 1 < vector.x \
		|| vector.y < -1 || 1 < vector.y \
		|| vector.z < -1 || 1 < vector.z)
		return (FALSE);
	if (!vector.x && !vector.y && !vector.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_FOV(int FOV)
{
	if (FOV < 0 || 180 < FOV)
		return (FALSE);
	return (TRUE);
}
