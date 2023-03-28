/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:10:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:43:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_img(t_game *game);
static int	fruit_img(t_game *game, char *str);

int	init_img(t_game *game)
{
	if (map_img(game) == -1
		|| fruit_img(game, ft_strdup("textures/fruits/0.png")) == -1
		|| stand_img(game, ft_strdup("textures/stand/stand0-0.png")) == -1
		|| walk_img(game, ft_strdup("textures/walk/walk0-0.png")) == -1
		|| jump_img(game, ft_strdup("textures/jump/jump0-00.png")) == -1
		|| rest_img(game, ft_strdup("textures/rest/rest0-00.png")) == -1
		|| sleep_img(game, ft_strdup("textures/sleep/sleep0-0.png")) == -1)
		return (-1);
	return (0);
}

static int	map_img(t_game *game)
{
	game->map_img[0].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/grass.png",
			&game->map_img[0].width, &game->map_img[0].height);
	game->map_img[1].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/tree.png",
			&game->map_img[1].width, &game->map_img[1].height);
	game->map_img[2].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/exit.png",
			&game->map_img[2].width, &game->map_img[2].height);
	game->map_img[3].img_ptr = mlx_png_file_to_image
		(game->mlx, "textures/map/background.png",
			&game->map_img[3].width, &game->map_img[3].height);
	if (!game->map_img[0].img_ptr || !game->map_img[1].img_ptr
		|| !game->map_img[2].img_ptr || !game->map_img[3].img_ptr)
		return (-1);
	return (0);
}

static int	fruit_img(t_game *game, char *str)
{
	int	num;

	num = 0;
	if (!str)
		return (-1);
	while (num < 5)
	{
		str[16] = num + '0';
		game->fruit[num].img_ptr = mlx_png_file_to_image
			(game->mlx, str, &game->fruit[num].width, &game->fruit[num].height);
		if (!game->fruit[num].img_ptr)
			return (free_n_print_out(2, 0, str, 0));
		num++;
	}
	return (free_n_print_out(1, 0, str, 0));
}
