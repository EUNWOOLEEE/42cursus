/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:48 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/16 15:33:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	close_all_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_num)
	{
		close(data->cmd[i].fd[P_READ]);
		close(data->cmd[i].fd[P_WRITE]);
		i++;
	}
}