/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/18 21:58:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_pipe(t_data *data, int idx);
void	link_pipe(t_data *data, int i);
void	close_pipe(t_data *data, int i);

void	get_pipe(t_data *data, int idx)
{
	if (pipe(data->cmd[idx].fd) == -1)
		print_error("Create pipe failure");
}

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
