/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:16:05 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 14:23:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_color	color_plus(t_color color, double t)
{
	color.x += t;
	color.y += t;
	color.z += t;
	return (color);
}

t_color	color_minus(t_color color, double t)
{
	color.x -= t;
	color.y -= t;
	color.z -= t;
	return (color);
}

t_color	color_multi(t_color color, double t)
{
	color.x *= t;
	color.y *= t;
	color.z *= t;
	return (color);
}

t_color	color_divide(t_color color, double t)
{
	color.x /= t;
	color.y /= t;
	color.z /= t;
	return (color);
}

