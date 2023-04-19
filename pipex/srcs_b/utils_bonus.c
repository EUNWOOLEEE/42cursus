/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:48 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/19 17:13:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	free_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->cmd_num)
	{
		j = 0;
		while (data->cmd[i].cmd_arg[j])
			free(data->cmd[i].cmd_arg[j++]);
		free(data->cmd[i++].cmd_arg);
	}
	free(data->cmd);
	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free(data->path);
	free(data);

}
