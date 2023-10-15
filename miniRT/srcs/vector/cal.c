/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:45:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 21:38:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	vec_cal(t_vec vec, double value, char operator)
{
	if (operator == '+')
	{
		vec.x += value;
		vec.y += value;
		vec.z += value;
	}
	else if (operator == '-')
	{
		vec.x -= value;
		vec.y -= value;
		vec.z -= value;
	}
	else if (operator == '*')
	{
		vec.x *= value;
		vec.y *= value;
		vec.z *= value;
	}
	else if (operator == '/')
	{
		vec.x /= value;
		vec.y /= value;
		vec.z /= value;
	}
	return (vec);
}

t_vec	vec_n_vec_cal(t_vec vec1, t_vec vec2, char operator)
{
	if (operator == '+')
	{
		vec1.x += vec2.x;
		vec1.y += vec2.y;
		vec1.z += vec2.z;
	}
	else if (operator == '-')
	{
		vec1.x -= vec2.x;
		vec1.y -= vec2.y;
		vec1.z -= vec2.z;
	}
	else if (operator == '*')
	{
		vec1.x *= vec2.x;
		vec1.y *= vec2.y;
		vec1.z *= vec2.z;
	}
	else if (operator == '/')
	{
		vec1.x /= vec2.x;
		vec1.y /= vec2.y;
		vec1.z /= vec2.z;
	}
	return (vec1);
}

