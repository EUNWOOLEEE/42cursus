/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:35:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:23:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_next_pos(t_game *game)
{
	if (game->map->map[game->next.row][game->next.col] == '1')
		return (-1);
	if (game->map->map[game->next.row][game->next.col] == 'C')
		game->flag.fruit = 1;
	return (0);
}

int key_press(int keycode, t_game *game)
{
	if ((keycode == 13 || keycode == 126) && !check_next_pos(game))
	{
		game->next.row--;
		move(game, 0);
	}
	else if (keycode == 0 || keycode == 123)
	{
		game->cur_dir = 0;
		if (!check_next_pos(game))
		{
			game->next.col--;
			move(game, 1);
		}
	}
	else if ((keycode == 1 || keycode == 125) && !check_next_pos(game))
	{
		game->next.row++;
		move(game, 2);
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->cur_dir = 1;
		if (!check_next_pos(game))
		{
			game->next.col++;
			move(game, 3);
		}
	}
	else if(keycode == 53)
	{
		return (0);
	}
	game->cur.row = game->next.row;
	game->cur.col = game->next.col;
	return (0);
}

int key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	printf("key release\n");
	return (0);
}

int standing(t_game *game)
{
	int stand;

	stand = 0;
	if (game->cur.row == game->next.row && game->cur.col == game->next.col)
	{
		// while (stand < 5)
		// {
		// 	draw_sprite(game, game->map_img[0], game->cur.row * 32, game->cur.col * 32);
		// 	draw_sprite(game, game->stand[game->cur_dir][stand], 
		// 		(game->cur.row * 32) + game->pos.fox_row, (game->cur.col * 32) + game->pos.fox_col);
		// 	mlx_sync(2, game->win);
		// 	stand++;
		// }
		if (game->frame < 8)
			stand = 0;
		else if (game->frame < 16)
			stand = 1;
		else if (game->frame < 24)
			stand = 2;
		else if (game->frame < 32)
			stand = 3;
		else if (game->frame < 40)
			stand = 4;
		draw_sprite(game, game->map_img[0], game->cur.row * 32, game->cur.col * 32);
		draw_sprite(game, game->stand[game->cur_dir][stand], 
			(game->cur.row * 32) + game->pos.fox_row, (game->cur.col * 32) + game->pos.fox_col);
		// mlx_sync(2, game->win);
	}
	game->frame++;
	if (game->frame == 40)
		game->frame = 0;
	return (0);
}
