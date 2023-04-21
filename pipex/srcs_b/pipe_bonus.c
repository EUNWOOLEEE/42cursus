/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/21 14:31:30 by eunwolee         ###   ########.fr       */
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
		close(data->cmd[cur].fd[P_READ]);
		dup2(data->infile, STDIN_FILENO);
		dup2(data->cmd[cur].fd[P_WRITE], STDOUT_FILENO);
	}
	else if (cur == data->cmd_num - 1)
	{
		close(data->cmd[pre].fd[P_WRITE]);
		dup2(data->cmd[pre].fd[P_READ], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	else
	{
		close(data->cmd[cur].fd[P_READ]);
		dup2(data->cmd[pre].fd[P_READ], STDIN_FILENO);
		dup2(data->cmd[cur].fd[P_WRITE], STDOUT_FILENO);
	}
}

void	close_pipe(t_data *data, int cur, int pre)
{
	if (cur == 0)
		close(data->cmd[cur].fd[P_WRITE]);
	else if (cur == data->cmd_num - 1)
		close(data->cmd[pre].fd[P_READ]);
	else
	{
		close(data->cmd[pre].fd[P_READ]);
		close(data->cmd[cur].fd[P_WRITE]);
	}
}
