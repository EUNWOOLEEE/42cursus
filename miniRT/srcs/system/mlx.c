/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:30:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 15:22:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

int	key_press(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		exit(0);
	}
	return (0);
}

int	red_cross_press(void)
{
	exit(0);
}

t_bool	mlx_set(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->img.w, scene->img.h, "miniRT");
	if (!scene->mlx_ptr || !scene->win_ptr)
		return (FALSE);
	// mlx_hook(scene->win_ptr, 2, 0, key_press, scene);
	// mlx_hook(scene->win_ptr, 17, 0, red_cross_press, scene);
	// mlx_loop(scene->mlx_ptr);
	return (TRUE);
}