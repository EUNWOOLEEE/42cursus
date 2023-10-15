/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:35:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 21:28:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_color	rgb_cal(t_color rgb, double value, char operator)
{
	if (operator == '+')
	{
		rgb.x += value;
		rgb.y += value;
		rgb.z += value;
	}
	else if (operator == '-')
	{
		rgb.x -= value;
		rgb.y -= value;
		rgb.z -= value;
	}
	else if (operator == '*')
	{
		rgb.x *= value;
		rgb.y *= value;
		rgb.z *= value;
	}
	else if (operator == '/')
	{
		rgb.x /= value;
		rgb.y /= value;
		rgb.z /= value;
	}
	return (rgb);
}

t_color	rgb_n_rgb_cal(t_color rgb1, t_color rgb2, char operator)
{
	if (operator == '+')
	{
		rgb1.x += rgb2.x;
		rgb1.y += rgb2.y;
		rgb1.z += rgb2.z;
	}
	else if (operator == '-')
	{
		rgb1.x -= rgb2.x;
		rgb1.y -= rgb2.y;
		rgb1.z -= rgb2.z;
	}
	else if (operator == '*')
	{
		rgb1.x *= rgb2.x;
		rgb1.y *= rgb2.y;
		rgb1.z *= rgb2.z;
	}
	else if (operator == '/')
	{
		rgb1.x /= rgb2.x;
		rgb1.y /= rgb2.y;
		rgb1.z /= rgb2.z;
	}
	return (rgb1);
}

