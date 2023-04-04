/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:48:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 18:46:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_end(t_game *game);

void	game_end(t_game *game)
{
	if (game->flag.exit)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}
