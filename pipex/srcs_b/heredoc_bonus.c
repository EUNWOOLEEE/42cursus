/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/19 21:08:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void		heredoc(t_data *data, int argc, char **argv);
static void	get_data(t_data *data, int argc, char **argv);
static void	get_input(t_data *data);

void	heredoc(t_data *data, int argc, char **argv)
{
	get_data(data, argc, argv);
	get_input(data);
}

static void	get_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data->infile = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (data->infile == -1)
		perror("File open failure");
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	if (data->outfile == -1)
		print_error("File open failure");
	data->limiter = argv[2];
	while (i < data->cmd_num)
	{
		data->cmd[i].cmd_arg = ft_split(argv[i + 3], ' ');
		if (!data->cmd[i].cmd_arg)
			print_error("Cannot allocate memory");
		data->cmd[i].slash = check_slash(data->cmd[i].cmd_arg[0]);
		i++;
	}
}

static void	get_input(t_data *data)
{
	char	*line;

	line = get_next_line(1);
	if (!line || !ft_strncmp(line, data->limiter, ft_strlen(data->limiter)))
		return ;
	while (line)
	{
		write(data->infile, line, ft_strlen(line));
		free(line);
		line = get_next_line(1);
		if (!ft_strncmp(line, data->limiter, ft_strlen(data->limiter)))
		{
			free(line);
			return ;
		}
	}
}
