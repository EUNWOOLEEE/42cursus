/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:28:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 18:28:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
	{
		printf("Usage: ratio in range [0.0,1.0");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_color(t_color color)
{
	if (color.R < 0 || 255 < color.R \
		|| color.G < 0 || 255 < color.G \
		|| color.B < 0 || 255 < color.B)
	{
		printf("Usage: R,G,B [0-255]\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_vector(t_coor vector)
{
	if (vector.x < -1 || 1 < vector.x \
		|| vector.y < -1 || 1 < vector.y \
		|| vector.z < -1 || 1 < vector.z)
	{
		printf("Usage: 3d normalized normal vector. In range [-1,1] for each x,y,z axis\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_FOV(int FOV)
{
	if (FOV < 0 || 180 < FOV)
	{
		printf("Usage: FOV in degrees in range [0,180]\n");
		return (FALSE);
	}
	return (TRUE);
}
