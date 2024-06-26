/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/02 16:51:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void			heredoc(t_data *data, int argc, char **argv);
static void		get_data(t_data *data, int argc, char **argv);
static void		get_input(t_data *data);
static t_bool	check_limiter(char *limiter, char *line);
static void		re_open(t_data *data);

void	heredoc(t_data *data, int argc, char **argv)
{
	get_data(data, argc, argv);
	get_input(data);
	re_open(data);
}

static void	get_data(t_data *data, int argc, char **argv)
{
	int	i;
	int	cnt;

	i = 0;
	data->infile = open("/tmp/heredoc", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (data->infile == -1)
		perror("File open failure");
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (data->outfile == -1)
		print_error("File open failure");
	data->limiter = argv[2];
	while (i < data->cmd_num)
	{
		cnt = check_quote(argv[i + 3]);
		if (cnt > 0)
			data->cmd[i].cmd_arg = split_quote(argv[i + 3], ' ', cnt);
		else
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

	line = get_next_line(0);
	if (!line)
		return ;
	if (check_limiter(data->limiter, line) == TRUE)
	{
		free(line);
		return ;
	}
	while (line)
	{
		write(data->infile, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
		if (!line)
			return ;
		if (check_limiter(data->limiter, line) == TRUE)
		{
			free(line);
			return ;
		}
	}
}

static t_bool	check_limiter(char *limiter, char *line)
{
	if (ft_strlen(limiter) != ft_strlen(line) - 1)
		return (FALSE);
	if (ft_strncmp(limiter, line, ft_strlen(line) - 1))
		return (FALSE);
	return (TRUE);
}

static void	re_open(t_data *data)
{
	close(data->infile);
	data->infile = open("/tmp/heredoc", O_RDONLY);
	if (data->infile == -1)
		perror("File open failure");
}
