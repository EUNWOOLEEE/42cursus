/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/04 11:14:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_pipe(t_data *data, int idx);
void	link_pipe(t_data *data, int cur, int pre);
void	close_pipe(t_data *data, int cur, int pre);

void	get_pipe(t_data *data, int idx)
{
	if (pipe(data->cmd[idx].fd) == -1)
		print_error("Create pipe failure");
}

void	link_pipe(t_data *data, int cur, int pre)
{
	if (cur == 0)
	{
		if (close(data->cmd[cur].fd[P_READ]) == -1
			|| dup2(data->infile, STDIN_FILENO) == -1
			|| dup2(data->cmd[cur].fd[P_WRITE], STDOUT_FILENO) == -1)
			print_error("Link pipe failure");
	}
	else if (cur == data->cmd_num - 1)
	{
		if (close(data->cmd[pre].fd[P_WRITE]) == -1
			|| dup2(data->cmd[pre].fd[P_READ], STDIN_FILENO) == -1
			|| dup2(data->outfile, STDOUT_FILENO) == -1)
			print_error("Link pipe failure");
	}
	else
	{
		if (close(data->cmd[cur].fd[P_READ]) == -1
			|| dup2(data->cmd[pre].fd[P_READ], STDIN_FILENO) == -1
			|| dup2(data->cmd[cur].fd[P_WRITE], STDOUT_FILENO) == -1)
			print_error("Link pipe failure");
	}
}

void	close_pipe(t_data *data, int cur, int pre)
{
	if (cur == 0)
	{
		if (close(data->cmd[cur].fd[P_WRITE]) == -1)
			print_error("Close pipe failure");
	}
	else if (cur == data->cmd_num - 1)
	{
		if (close(data->cmd[pre].fd[P_READ]) == -1)
			print_error("Close pipe failure");
	}
	else
	{
		if (close(data->cmd[pre].fd[P_READ]) == -1
			|| close(data->cmd[cur].fd[P_WRITE]) == -1)
			print_error("Close pipe failure");
	}
}
