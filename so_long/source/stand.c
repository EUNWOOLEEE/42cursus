/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/01 12:11:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_flag(t_game *game);
static void	draw_motion(t_game *game);
static int	check_reset_point(t_game *game);

void	standing(t_game *game)
{
	set_flag(game);
	// printf("standing %d\n", game->flag.motion);
	draw_motion(game);
	game->frame++;
	if (check_reset_point(game))
	{
		game->frame = 0;
		game->flag.motion++;
	}
}

static void	set_flag(t_game *game)
{
	game->flag.rest = 0;
	game->flag.stand = 0;
	game->flag.sleep = 0;
	if (game->cur.row == game->next.row && game->cur.col == game->next.col)
	{
		// printf("set flag %d\n", game->flag.motion);
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

static void	draw_motion(t_game *game)
{
	// printf("draw motion rest: %d stand :%d sleep: %d\n", game->flag.rest, game->flag.stand, game->flag.sleep);
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
