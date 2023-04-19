/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/19 18:27:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc < 5)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		return (0);
	}
	init_data(&data, argc, argv, envp);
	execute_pipex(data, envp);
	wait_child(data);
	free_data(data);
	return (0);
}
