/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:02:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 22:06:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_sphere	sphere(t_point center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	return (sp);
}

t_bool	sphere_hit(t_point p, t_sphere sp)
{
	
}