/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:16:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:49:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_color	color(double R, double G, double B)
{
	t_color	color;

	color.x = R;
	color.y = G;
	color.z = B;
	return (color);
}

int		color_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	color_to_albedo(t_color color)
{
	color.x /= 255;
	color.y /= 255;
	color.z /= 255;
	return (color);
}