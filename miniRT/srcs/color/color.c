/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:38:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/13 21:32:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	rgb_set(t_color *rgb, double R, double G, double B)
{
	rgb->x = R;
	rgb->y = G;
	rgb->z = B;
}

void	rgb_n_rgb_set(t_color *rgb1, t_color rgb2)
{
	rgb1->x = rgb2.x;
	rgb1->y = rgb2.y;
	rgb1->z = rgb2.z;
}
