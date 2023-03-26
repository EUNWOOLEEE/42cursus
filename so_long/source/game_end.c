/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:48:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 20:12:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char *tmp;

// 	tmp = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)tmp = color;
// }

int game_end(t_game *game)
{
	if (game->flag.exit)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}