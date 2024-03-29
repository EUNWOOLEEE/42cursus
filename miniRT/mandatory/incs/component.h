/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:24:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 13:24:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;
typedef struct s_vec	t_color;

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
	double	d;
	double	t;
}t_discriminant;

#endif