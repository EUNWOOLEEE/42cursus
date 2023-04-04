/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 20:59:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void		error_exit(char *str);
void		print_move(t_game *game);
void		copy_map(t_game *game);
static void	cover(t_game *game);

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	exit(1);
}

void	print_move(t_game *game)
{
	char	*s1;
	char	*s2;
	char	*res;

	ft_putstr_fd("move: ", 1);
	ft_putnbr_fd(game->move_cnt, 1);
	ft_putchar_fd('\n', 1);
	s1 = ft_strdup("move: ");
	s2 = ft_itoa(game->move_cnt);
	res = ft_strjoin(s1, s2);
	cover(game);
	mlx_string_put(game->mlx, game->win, 13, 20, 0xFFFFFF, res);
	free(s1);
	free(s2);
	free(res);
}

void	copy_map(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.height)
	{
		ft_memmove(game->map.tmp[i], game->map.map[i],
			sizeof(char) * game->map.width);
		i++;
	}
}

static void	cover(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		draw_img(game, game->map_img[0], 0, i * 32);
		draw_img(game, game->map_img[1],
			0 + game->dis.tree_row, i * 32 + game->dis.tree_col);
		i++;
	}
}
