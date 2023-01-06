/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/01/06 23:07:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line_bonus.h"

t_list	*get_new_nod(char *buff, int fd)
{
	t_list	*nod;

	if (!buff)
		return (0);
	nod = (t_list *)malloc(sizeof(t_list) * 1);
	if (!nod)
	{
		free(buff);
		return (0);
	}
	nod->buff = buff;
	nod->fd = fd;
	nod->next = 0;
	return (nod);
}

t_list	*get_fd_nod(t_list **head, int fd)
{
	t_list	*tmp;

	tmp = *head;
	if (!tmp)
	{
		tmp = get_new_nod(ft_strdup(""), fd);
		if (!tmp)
			return (0);
		*head = tmp;
	}
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd != fd)
	{
		tmp->next = get_new_nod(ft_strdup(""), fd);
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (tmp);
}

static char	*get_done_line(t_list *nod)
{
	int		idx;
	int		nod_cnt;
	int		line_cnt;
	char	*line;

	line_cnt = 0;
	while (nod->buff[line_cnt] != '\n' && nod->buff[line_cnt])
		line_cnt++;
	if (nod->buff[line_cnt] == '\n')
		line_cnt++;
	nod_cnt = ft_strlen(&nod->buff[line_cnt]);
	line = (char *)malloc(sizeof(char) * (line_cnt + 1));
	if (!line)
		return (0);
	idx = -1;
	while (++idx < line_cnt)
		line[idx] = nod->buff[idx];
	idx = -1;
	while (++idx < nod_cnt)
		nod->buff[idx] = nod->buff[idx + line_cnt];
	line[line_cnt] = '\0';
	nod->buff[nod_cnt] = '\0';
	return (line);
}

static int	get_read_line(int fd, char *buff, t_list *nod)
{
	int		rd;
	char	*tmp;

	rd = 1;
	while (rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (-1);
		if (!rd)
			break ;
		buff[rd] = '\0';
		tmp = nod->buff;
		nod->buff = ft_strjoin(tmp, buff);
		free(tmp);
		if (!nod->buff)
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_list			*nod;
	char			*buff;
	char			*line;
	static t_list	*head;

	if (fd < 0 || BUFFER_SIZE <= 0) //|| read(fd, 0, 0) == -1)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	nod = get_fd_nod(&head, fd);
	if (!nod)
	{
		free(buff);
		return (0);
	}
	if (get_read_line(fd, buff, nod) == -1 || !*(nod->buff))
	{
		free(buff);
		return (delete_nod(&head, nod));
	}
	free(buff);
	if (!nod->buff)
		return (delete_nod(&head, nod));
	line = get_done_line(nod);
	if (!line)
		return (delete_nod(&head, nod));
	if (!*(nod->buff))
		delete_nod(&head, nod);
	return (line);
}

