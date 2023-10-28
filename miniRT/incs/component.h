/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   COMPONENT.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:34:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 15:38:50 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_vec t_color;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}t_ray;

typedef struct discriminant
{
	double	a;
	double	half_b;
	double	c;
	double	D;
	double	t;
}t_discriminant;

#endif