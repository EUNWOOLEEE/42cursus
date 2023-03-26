/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:10:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 17:50:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void map_img(t_game *game);
static int fruit_img(t_game *game);

int init_img(t_game *game)
{
	map_img(game);
	if (fruit_img(game) == -1 || stand_img(game) == -1 || walk_img(game) || 
		jump_img(game) || rest_img(game) || sleep_img(game))
		return (-1);
	return (0);
}

static void map_img(t_game *game)
{
	game->map_img[0].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/grass.png", &game->map_img[0].width, &game->map_img[0].height);
	game->map_img[1].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/tree.png", &game->map_img[1].width, &game->map_img[1].height);
	game->map_img[2].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/exit.png", &game->map_img[2].width, &game->map_img[2].height);
}

static int fruit_img(t_game *game)
{
	int num;
	char *fruit;

	num = 0;
	fruit = ft_strdup("textures/fruits/0.png");
	if (!fruit)
		return (-1);
	while (num < 5)
	{
		fruit[16] = num + '0';
		game->fruit[num].img_ptr = mlx_png_file_to_image
		(game->mlx, fruit, &game->fruit[num].width, &game->fruit[num].height);
		num++;
	}
	return (free_n_print_out(1, 0, fruit, 0));
}
