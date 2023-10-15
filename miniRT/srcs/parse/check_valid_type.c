/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:28:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 14:17:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
		return (FALSE);
	return (TRUE);
}

t_bool	check_rgb(t_color rgb)
{
	if (rgb.x < 0 || 255 < rgb.x \
		|| rgb.y < 0 || 255 < rgb.y \
		|| rgb.z < 0 || 255 < rgb.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_vector(t_coor vector)
{
	if (vector.x < -1 || 1 < vector.x \
		|| vector.y < -1 || 1 < vector.y \
		|| vector.z < -1 || 1 < vector.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_FOV(int FOV)
{
	if (FOV < 0 || 180 < FOV)
		return (FALSE);
	return (TRUE);
}
