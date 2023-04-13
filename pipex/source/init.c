/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:17:18 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/13 18:18:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void get_path(t_data *data, char **envp);
static void get_data(t_data *data, int argc, char **argv);
static void	get_pipe(t_data *data);

void	init_data(t_data **data, int argc, char **argv, char **envp)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		print_error("Cannot allocate memory");
	(*data)->cmd_num = argc - 3;
	(*data)->cmd = (t_cmd *)ft_calloc((*data)->cmd_num, sizeof(t_cmd));
	if (!(*data)->cmd)
		print_error("Cannot allocate memory");
	get_path(*data, envp);
	get_data(*data, argc, argv);
	get_pipe(*data);
}

static void get_path(t_data *data, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			data->path = ft_split(&envp[i][5], ':');
			if (!data->path)
				print_error("Cannot allocate memory");
			return ;
		}
		i++;
	}
}

static void get_data(t_data *data, int argc, char **argv)
{
	int	i = 2;
	
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		perror("File open failure");
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC , S_IRUGO | S_IWUSR);
	while (i < argc)
	{
		data->cmd[i - 2].cmd_arg = ft_split(argv[i], ' ');
		if (!data->cmd[i - 2].cmd_arg)
			print_error("Cannot allocate memory");
		i++;
	}
}

static void	get_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_num)
	{
		if (pipe(data->cmd[i].fd) == -1)
			print_error("Create pipe failure");
		i++;
	}
}
