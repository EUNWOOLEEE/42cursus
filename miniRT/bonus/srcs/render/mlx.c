/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:30:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 17:13:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	mlx_set_ptr(t_scene *scene);
void	mlx_set_loop(t_scene *scene);
static int	key_press(int keycode, t_scene *scene);
static int	red_cross_press(t_scene *scene);

t_bool	mlx_set_ptr(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->img.w, scene->img.h, "miniRT");
	if (!scene->mlx_ptr || !scene->win_ptr)
		return (FALSE);
	return (TRUE);
}

void	mlx_set_loop(t_scene *scene)
{
	mlx_hook(scene->win_ptr, 2, 0, key_press, scene);
	mlx_hook(scene->win_ptr, 17, 0, red_cross_press, scene);
	mlx_loop(scene->mlx_ptr);
}

static int	key_press(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		mlx_destroy_image(scene->mlx_ptr, scene->img.ptr);
		exit(0);
	}
	return (0);
}

static int	red_cross_press(t_scene *scene)
{
	mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	mlx_destroy_image(scene->mlx_ptr, scene->img.ptr);
	exit(0);
}
