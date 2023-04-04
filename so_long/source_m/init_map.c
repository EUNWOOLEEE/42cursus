/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:08 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/04 18:46:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void			get_map(t_game *game, int fd);
static void		create_map(t_game *game);
static t_list	*get_map_line(int fd);
static void		fill_map(t_game *game, t_list *list);
static void		check_char(t_game *game, char c, int h, int w);

void	get_map(t_game *game, int fd)
{
	t_list	*head;

	head = get_map_line(fd);
	game->map.width = ft_strlen(head->content) - 1;
	game->map.height = ft_lstsize(head);
	create_map(game);
	fill_map(game, head);
	ft_lstclear(&head, free);
	check_valid(game);
}

static void	create_map(t_game *game)
{
	int	idx;

	idx = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	game->map.tmp = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.map || !game->map.tmp)
		error_exit(0);
	while (idx < game->map.height)
	{
		game->map.map[idx]
			= (char *)ft_calloc(game->map.width + 1, sizeof(char));
		game->map.tmp[idx]
			= (char *)ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.map[idx] || !game->map.tmp[idx])
			error_exit(0);
		idx++;
	}
}

static t_list	*get_map_line(int fd)
{
	t_list	*head;
	t_list	*new;
	char	*str;

	head = 0;
	str = get_next_line(fd);
	if (!str)
		error_exit(0);
	while (str)
	{
		new = ft_lstnew(str);
		if (!new)
			error_exit(0);
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	return (head);
}

static void	fill_map(t_game *game, t_list *list)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < game->map.height)
	{
		coor.col = 0;
		if (coor.row == game->map.height - 1)
		{
			if ((int)ft_strlen(list->content) != game->map.width)
				error_exit("Map is not rectangular\n");
		}
		else
		{
			if ((int)ft_strlen(list->content) - 1 != game->map.width)
				error_exit("Map is not rectangular\n");
		}
		while (coor.col < game->map.width)
		{
			check_char(game, list->content[coor.col], coor.row, coor.col);
			coor.col++;
		}
		list = list->next;
		coor.row++;
	}
}

static void	check_char(t_game *game, char c, int row, int col)
{
	if (c == 'P')
	{
		if (game->map.start[0])
			error_exit("Not one start point\n");
		game->map.start[0] = row;
		game->map.start[1] = col;
	}
	else if (c == 'E')
	{
		if (game->map.exit[0])
			error_exit("Not one exit point\n");
		game->map.exit[0] = row;
		game->map.exit[1] = col;
	}
	else if (c == 'C')
		game->map.col_num++;
	else if (c != '0' && c != '1')
		error_exit("Invaild character found\n");
	game->map.map[row][col] = c;
}
