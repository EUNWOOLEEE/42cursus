/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/01/02 16:32:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_done_line(char *line)
{
	int		idx;
	int		line_cnt;
	int		backup_cnt;
	char	*backup;

	line_cnt = 0;
	while (line[line_cnt] != '\n' && line[line_cnt])
		line_cnt++;
	if (line[line_cnt] == '\n')
		line_cnt++;
	backup_cnt = ft_strlen(&line[line_cnt]);
	backup = (char *)malloc(sizeof(char) * (backup_cnt + 1));
	if (!backup)
		return (0);
	idx = 0;
	while (idx < ft_strlen(&line[line_cnt]))
	{
		backup[idx] = line[line_cnt + idx];
		idx++;
	}
	backup[backup_cnt] = '\0';
	line[line_cnt] = '\0';
	return (backup);
}

static char	*get_read_line(int fd, char *buff, char *backup)
{
	int		rd;
	char	*tmp;

	rd = 1;
	while (rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (0);
		if (!rd)
			break ;
		buff[rd] = '\0';
		if (!backup)
			backup = ft_strdup("");
		if (!backup)
			return (0);
		tmp = backup;
		backup = ft_strjoin(tmp, buff);
		free(tmp);
		if (!backup)
			return (0);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*get_free_line(char *backup)
{
	free(backup);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	line = get_read_line(fd, buff, backup);
	free(buff);
	if (!line)
	{
		backup = get_free_line(backup);
		return (0);
	}
	backup = get_done_line(line);
	if (!*line)
	{
		free(line);
		backup = get_free_line(backup);
		return (0);
	}
	return (line);
}
