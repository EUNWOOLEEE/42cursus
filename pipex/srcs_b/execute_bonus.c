/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:58 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/19 22:34:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void		execute_pipex(t_data *data, char **envp);
void		execute_cmd(char **path_lst, t_cmd cmd, char **envp);
void		wait_child(t_data *data);
static char	*get_valid_path(char **path_lst, t_cmd cmd, int *res, int i);

void	execute_pipex(t_data *data, char **envp)
{
	int	idx;

	idx = 0;
	while (idx < data->cmd_num)
	{
		get_pipe(data, idx);
		data->cmd[idx].pid = fork();
		if (data->cmd[idx].pid == -1)
			print_error("Fork failure");
		if (!data->cmd[idx].pid)
		{
			link_pipe(data, idx);
			execute_cmd(data->path, data->cmd[idx], envp);
		}
		close_pipe(data, idx);
		if (!idx && data->heredoc == TRUE)
			unlink("/tmp/heredoc");
		idx++;
	}
}

void	execute_cmd(char **path_lst, t_cmd cmd, char **envp)
{
	int		res;
	char	*path;

	path = get_valid_path(path_lst, cmd, &res, 0);
	if (res == -1)
		print_error("Find command failure");
	if (execve(path, cmd.cmd_arg, envp) == -1)
	{
		free(path);
		print_error("Execute command failure");
	}
}

void	wait_child(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->cmd_num)
		waitpid(data->cmd[idx++].pid, 0, 0);
}

static char	*get_valid_path(char **path_lst, t_cmd cmd, int *res, int i)
{
	char	*tmp;
	char	*path;

	if (cmd.slash == TRUE)
	{
		path = ft_strdup(cmd.cmd_arg[0]);
		*res = access(path, X_OK);
	}
	else
	{
		while (path_lst[i])
		{
			tmp = ft_strjoin(path_lst[i], "/");
			path = ft_strjoin(tmp, cmd.cmd_arg[0]);
			free(tmp);
			*res = access(path, X_OK);
			if (!*res)
				break ;
			i++;
			free(path);
		}
	}
	return (path);
}
