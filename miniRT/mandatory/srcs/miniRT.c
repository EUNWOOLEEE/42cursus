/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:07:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 15:54:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = scene_init(argc, argv[1]);
	scene_read(scene);
	img_set(scene);
	cam_set(scene);
	mlx_set_ptr(scene);
	img_ptr_set(scene);
	draw_loop(scene);
	mlx_set_loop(scene);
	return (0);
}
