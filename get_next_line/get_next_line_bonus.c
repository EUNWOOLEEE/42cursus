/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/01/02 15:42:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line_bonus.h"

list	*get_new_nod(char *buff, int fd)
{
	list	*nod;

	nod = (list *)malloc(sizeof(list) * 1);
	if (!nod)
		return (0);
	nod->buff = buff;
	nod->fd = fd;
	nod->next = 0;
	return (nod);
}

void	delete_nod(list *backup, list *nod)
{
	while (backup->next->fd != nod->fd)
		backup = backup->next;
	backup->next = nod->next;
	free(nod);
}

static char	*get_done_line(list *nod)
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
	idx = 0;
	while (idx < line_cnt)
	{
		line[idx] = nod->buff[idx];
		idx++;
	}
	idx = 0;
	while (idx < nod_cnt)
	{
		nod->buff[idx] = nod->buff[idx + line_cnt];
		idx++;
	}
	line[line_cnt] = '\0';
	nod->buff[nod_cnt] = '\0';
	return (line);
}

static list	*get_read_line(int fd, char *buff, list *backup)
{
	int		rd;
	char	*tmp;

	if(!backup)
	{
		backup = get_new_nod(ft_strdup(""), fd);
		if (!backup)
			return (0);
	}

	while (backup->next)
	{
		if (backup->fd == fd)
			break;
		backup = backup->next;
	}
		
	if (backup->fd != fd)
	{
		backup->next = get_new_nod(ft_strdup(""), fd);
		if (!backup->next)
			return (0);
		backup = backup->next;
	}

	rd = 1;
	while (rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (0);
		if (!rd)
			break ;
		buff[rd] = '\0';

		tmp = backup->buff;

		backup->buff = ft_strjoin(tmp, buff);
		free(tmp);
		if (!backup->buff)
			return (0);

		if (ft_strchr(buff, '\n'))
				break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	list		*nod;
	list		*backup;
	char		*buff;
	char 		*line;
	static list	*head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	nod = get_read_line(fd, buff, head);
	if(!nod)
		return (0);
	if (!head)
		head = nod;
	else
	{
		backup = head;
		while(backup->next)
		{
			if(backup->fd == fd)
				break;
			backup = backup->next;
		}
		if(backup->fd == fd)
			backup = nod;
		else
			backup->next = nod;
	}
	free(buff);
	if (!nod->buff)
	{
		delete_nod(head, nod);
		return (0);
	}
	line = get_done_line(nod);
	if (!line)
	{
		delete_nod(head, nod);
		return (0);
	}

	return (line);
}
