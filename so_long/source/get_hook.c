/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:35:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 17:20:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int is_move_code(t_game *game, int keycode)
{
	if ((keycode == 13 || keycode == 126))
		return (0);
	else if (keycode == 0 || keycode == 123)
	{
		game->cur_dir = 0;
		return (1);
	}
	else if (keycode == 1 || keycode == 125)
		return (2);
	else if (keycode == 2 || keycode == 124)
	{
		game->cur_dir = 1;
		return (3);
	}
	return (-1);
}

int key_press(int keycode, t_game *game)
{
	int move_code;

	game->flag.motion = 0;
	if (game->flag.goal)
		return (0);
	if(keycode == 53)
	{
		game->flag.exit++;
		return (0);
	}
	move_code = is_move_code(game, keycode);
	if (move_code >= 0)
		move_ready(game, move_code);
	return (0);
}

int key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	printf("key release\n");
	return (0);
}
