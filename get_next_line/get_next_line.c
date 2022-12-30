/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:43 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/30 19:20:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include "get_next_line.h"

char *get_done_line(char *line) //개행을 기준으로 분리하는 함수
{
	int line_cnt;
	int backup_cnt;
	char *res;

	line_cnt = 0;
	while (line[line_cnt] != '\n' && line[line_cnt])
		line_cnt++;
	if(line[line_cnt] == '\n')
		line_cnt++;

	backup_cnt = ft_strlen(&line[line_cnt]);

	res = (char *)malloc(sizeof(char) * (backup_cnt + 1));
	if(!res)
		return (0);

	ft_memmove(res, &line[line_cnt], ft_strlen(&line[line_cnt]));
	res[backup_cnt] = '\0';
	line[line_cnt] = '\0';

	return res;
}

char *get_read_line(int fd, char *buff, char *backup) //문자열 읽어오는 함수
{
	int rd;
	char *tmp;

	rd = 1;
	while (rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);

		if(rd == -1)
			return (0);

		if(!rd)
			break;

		buff[rd] = '\0';

		if(!backup)
			backup = ft_strdup("");
			
		tmp = backup;
		backup = ft_strjoin(tmp, buff);
		free(tmp);
		
		if(ft_strchr(buff, '\n'))
			break;
	}
	
	return (backup);
}

char *get_next_line(int fd)
{
	char *line;
	char *buff;
	static char *backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);

	line = get_read_line(fd, buff, backup);
	free(buff);
	// buff = 0;

	if(!line)
		return (0);
	
	backup = get_done_line(line);
	if(!*line)
	{
		free(line);
		free(backup);
		return (0);
	}
	
	return line;
}