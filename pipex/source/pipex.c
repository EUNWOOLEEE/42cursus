/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/16 16:36:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void execute_cmd(char **path_lst, t_cmd cmd, char **envp);
char *get_valid_path(char **path_lst, t_cmd cmd, int *res, int i);

void	link_pipe(t_data *data, int i)
{
	if (i == 0)
	{
		close(data->cmd[i].fd[P_READ]);
		dup2(data->infile, STDIN_FILENO);
		dup2(data->cmd[i].fd[P_WRITE], STDOUT_FILENO);
	}
	else if (i == data->cmd_num - 1)
	{
		close(data->cmd[i - 1].fd[P_WRITE]);
		dup2(data->cmd[i - 1].fd[P_READ], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	else
	{
		close(data->cmd[i - 1].fd[P_WRITE]);
		close(data->cmd[i].fd[P_READ]);
		dup2(data->cmd[i - 1].fd[P_READ], STDIN_FILENO);
		dup2(data->cmd[i].fd[P_WRITE], STDOUT_FILENO);
	}
}

void	close_pipe(t_data *data, int i)
{
	if (i == 0)
		close(data->cmd[i].fd[P_WRITE]);
	else if (i == data->cmd_num - 1)
		close(data->cmd[i - 1].fd[P_READ]);
	else
	{
		close(data->cmd[i - 1].fd[P_READ]);
		close(data->cmd[i].fd[P_WRITE]);
	}
}

void execute_cmd(char **path_lst, t_cmd cmd, char **envp)
{
	int res;
	char *path;
	
	path = get_valid_path(path_lst, cmd, &res, 0);
	if (res == -1)
	{
		free(path);
		print_error("Find command failure");
	}
	if (execve(path, cmd.cmd_arg, envp) == -1)
	{
		free(path);
		print_error("Execute command failure");
	}
}

char *get_valid_path(char **path_lst, t_cmd cmd, int *res, int i)
{
	char *tmp;
	char *path;

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
				break;
			i++;
			free(path);
		}
	}
	return (path);
}

int main(int argc, char **argv, char **envp)
{
	int	idx;
	int status;
	t_data *data;

	// if (argc != 5) //보너스는 5 미만으로 바꾸기
	// 	return (0); // error
	init_data(&data, argc, argv, envp);
	idx = 0;
	while (idx < data->cmd_num)
	{
		data->cmd[idx].pid = fork();
		if (data->cmd[idx].pid == -1)
			print_error("Fork failure");
		if (!data->cmd[idx].pid) //child
		{
			link_pipe(data, idx);
			execute_cmd(data->path, data->cmd[idx], envp);
		}
		close_pipe(data, idx); //????????
		idx++;
	}
	idx = 0;
	while (idx < data->cmd_num)
		waitpid(data->cmd[idx++].pid, &status, 0);
	close_all_pipe(data);
	return (0);
}
