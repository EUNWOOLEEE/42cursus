/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:16:05 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 14:23:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_color	color_plus2(t_color color1, t_color color2)
{
	color1.x += color2.x;
	color1.y += color2.y;
	color1.z += color2.z;
	return (color1);
}

t_color	color_minus2(t_color color1, t_color color2)
{
	color1.x -= color2.x;
	color1.y -= color2.y;
	color1.z -= color2.z;
	return (color1);
}

t_color	color_multi2(t_color color1, t_color color2)
{
	color1.x *= color2.x;
	color1.y *= color2.y;
	color1.z *= color2.z;
	return (color1);
}

t_color	color_divide2(t_color color1, t_color color2)
{
	color1.x /= color2.x;
	color1.y /= color2.y;
	color1.z /= color2.z;
	return (color1);
}

