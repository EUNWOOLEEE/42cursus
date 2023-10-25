/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:33:05 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/23 20:24:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "component.h"

typedef struct s_sphere
{
	t_point	center;
	double	diameter;
	double	radius;
	double	radius_squared;
	t_color	color;
}t_sphere;

typedef struct s_plane
{
	t_point	center;
	t_vec	dir;
	t_color	color;
}t_plane;


typedef struct s_cylinder
{
	t_point	center;
	t_vec	dir;
	double	diameter;
	double	radius;
	double	radius_squared;
	double	h;
	t_color	color;
}t_cylinder;


typedef struct s_cone
{
	/* data */
}t_cone;

#endif