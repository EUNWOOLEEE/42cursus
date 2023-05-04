/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:17:18 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/04 11:24:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void			init_data(t_data **data, int argc, char **argv, char **envp);
t_bool			check_slash(char *cmd);
static void		get_path(t_data *data, char **envp);
static void		get_data(t_data *data, int argc, char **argv);

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
}

t_bool	check_slash(char *cmd)
{
	if (!ft_strncmp("/", cmd, 1) || !ft_strncmp("./", cmd, 2)
		|| !ft_strncmp("../", cmd, 3))
		return (TRUE);
	return (FALSE);
}

static void	get_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=/", 6))
		{
			data->path = ft_split(&envp[i][5], ':');
			if (!data->path)
				print_error("Cannot allocate memory");
			return ;
		}
		i++;
	}
}

static void	get_data(t_data *data, int argc, char **argv)
{
	int	i;
	int	cnt;

	i = 0;
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		perror("Infile open failure");
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		perror("Outfile open failure");
	while (i < data->cmd_num)
	{
		cnt = check_quote(argv[i + 2]);
		if (cnt > 0)
			data->cmd[i].cmd_arg = split_quote(argv[i + 2], ' ', cnt);
		else
			data->cmd[i].cmd_arg = ft_split(argv[i + 2], ' ');
		if (!data->cmd[i].cmd_arg)
			print_error("Cannot allocate memory");
		data->cmd[i].slash = check_slash(data->cmd[i].cmd_arg[0]);
		i++;
	}
}
