/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:10:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 18:46:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void		init_img(t_game *game);
static void	map_img(t_game *game);
static void	fruit_img(t_game *game, char *str);

void	init_img(t_game *game)
{
	map_img(game);
	fruit_img(game, ft_strdup("textures/fruits/0.png"));
	stand_img(game, ft_strdup("textures/stand/stand0-0.png"));
	walk_img(game, ft_strdup("textures/walk/walk0-0.png"));
	jump_img(game, ft_strdup("textures/jump/jump0-00.png"));
	rest_img(game, ft_strdup("textures/rest/rest0-00.png"));
	sleep_img(game, ft_strdup("textures/sleep/sleep0-0.png"));
}

static void	map_img(t_game *game)
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
	if (!game->map_img[0].img_ptr || !game->map_img[1].img_ptr
		|| !game->map_img[2].img_ptr)
		error_exit(0);
}

static void	fruit_img(t_game *game, char *str)
{
	int	num;

	num = 0;
	if (!str)
		error_exit(0);
	while (num < 5)
	{
		str[16] = num + '0';
		game->fruit[num].img_ptr = mlx_png_file_to_image
			(game->mlx, str, &game->fruit[num].width, &game->fruit[num].height);
		if (!game->fruit[num].img_ptr)
			error_exit(0);
		num++;
	}
	free(str);
}
