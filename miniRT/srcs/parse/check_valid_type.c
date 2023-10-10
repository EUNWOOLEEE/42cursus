/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:28:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 20:34:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
		return (FALSE);
	return (TRUE);
}

t_bool	check_rgb(t_rgb rgb)
{
	if (rgb.R < 0 || 255 < rgb.R \
		|| rgb.G < 0 || 255 < rgb.G \
		|| rgb.B < 0 || 255 < rgb.B)
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
