/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:08 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/01 12:17:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*0 : 빈 공간
1 : 벽
C : 수집품
E : 맵의 출구
P : 캐릭터의 시작 지점*/

static t_list	*get_map_line(int fd);
static void		fill_map(t_map *map, t_list *list);
static void		check_char(t_map *map, char c, int h, int w);

t_map	*get_map(int fd)
{
	t_list	*head;
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		error_exit();
	head = get_map_line(fd);
	map->width = ft_strlen(head->content) - 1; //개행
	map->height = ft_lstsize(head);
	create_map(map);
	fill_map(map, head);
	ft_lstclear(&head, free);
	check_valid(map);
	return (map);
}

void	create_map(t_map *map)
{
	int	idx;

	idx = 0;
	map->map = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		error_exit(0);
	while (idx < map->height)
	{
		map->map[idx] = (char *)ft_calloc(map->width + 1, sizeof(char));
		if (!map->map[idx])
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

static void	fill_map(t_map *map, t_list *list)
{
	t_coor	coor;

	coor.row = 0;
	while (coor.row < map->height)
	{
		coor.col = 0;
		if (coor.row == map->height - 1)
		{
			if ((int)ft_strlen(list->content) != map->width)
				error_exit("Map is not rectangular\n");
		}
		else
		{
			if ((int)ft_strlen(list->content) - 1 != map->width)
				error_exit("Map is not rectangular\n");
		}
		while (coor.col < map->width)
		{
			check_char(map, list->content[coor.col], coor.row, coor.col);
			coor.col++;
		}
		list = list->next;
		coor.row++;
	}
}

static void	check_char(t_map *map, char c, int row, int col)
{
	if (c == 'P')
	{
		if (map->start[0])
			error_exit("Not one start point\n");
		map->start[0] = row;
		map->start[1] = col;
	}
	else if (c == 'E')
	{
		if (map->exit[0])
			error_exit("Not one exit point\n");
		map->exit[0] = row;
		map->exit[1] = col;
	}
	else if (c == 'C')
		map->col_num++;
	else if (c != '0' && c != '1')
		error_exit("Invaild character found\n");
	map->map[row][col] = c;
}
