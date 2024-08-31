/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:35:02 by eunwolee          #+#    #+#             */
/*   Updated: 2024/08/31 14:42:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int			key_press(int keycode, t_game *game);
int			red_cross_press(t_game *game);
static int	is_move_code(t_game *game, int keycode);

int	key_press(int keycode, t_game *game)
{
	int	move_code;

	game->frame = 0;
	game->flag.motion = 0;
	if (keycode == 53)
	{
		game->flag.exit++;
		return (0);
	}
	if (game->flag.goal || game->flag.hole)
		return (0);
	move_code = is_move_code(game, keycode);
	if (move_code >= 0)
		move_ready(game, move_code);
	return (0);
}

int	red_cross_press(t_game *game)
{
	game->flag.exit++;
	return (0);
}

static int	is_move_code(t_game *game, int keycode)
{
	if ((keycode == 13 || keycode == 126))
		return (MOVE_UP);
	else if (keycode == 0 || keycode == 123)
	{
		game->cur_dir = DIR_LEFT;
		return (MOVE_LEFT);
	}
	else if (keycode == 1 || keycode == 125)
		return (MOVE_DOWN);
	else if (keycode == 2 || keycode == 124)
	{
		game->cur_dir = DIR_RIGHT;
		return (MOVE_RIGHT);
	}
	return (-1);
}
