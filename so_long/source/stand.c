/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:37:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_flag(t_game *game);
static void	draw_motion(t_game *game);
static int	check_reset_point(t_game *game);

void	standing(t_game *game)
{
	set_flag(game);
	draw_motion(game);
	game->frame++;
	if (check_reset_point(game))
	{
		game->frame = 0;
		game->flag.motion++;
	}
}

static void	draw_motion(t_game *game)
{
	draw_img(game, game->map_img[0], game->cur.row * 32, game->cur.col * 32);
	if (game->flag.rest)
		draw_img(game, game->rest[game->cur_dir][game->frame / 8],
			game->cur.row * 32, game->cur.col * 32);
	else if (game->flag.stand)
		draw_img(game, game->stand[game->cur_dir][game->frame / 8],
			game->cur.row * 32, game->cur.col * 32);
	else if (game->flag.sleep)
		draw_img(game, game->sleep[game->cur_dir][game->frame / 8],
			game->cur.row * 32, game->cur.col * 32);
}

static void	set_flag(t_game *game)
{
	game->flag.rest = 0;
	game->flag.stand = 0;
	game->flag.sleep = 0;
	if (game->cur.row == game->next.row && game->cur.col == game->next.col)
	{
		if (game->flag.motion < 29)
		{
			if (game->flag.motion && !(game->flag.motion % 10))
				game->flag.rest = 1;
			else
				game->flag.stand = 1;
		}
		else
			game->flag.sleep = 1;
	}
}

static int	check_reset_point(t_game *game)
{
	if (game->flag.rest && game->frame == 112)
		return (1);
	if (game->flag.stand && game->frame == 40)
		return (1);
	if (game->flag.sleep && game->frame == 48)
		return (1);
	return (0);
}
