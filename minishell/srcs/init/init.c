/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/04 08:51:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

bool	init(t_data **data, char **envp)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		return (false);
	init_env(*data, envp);
	return (true);
}

bool	init_env(t_data *data, char **envp)
{
	int	i;

	data->table_size = 10; //임의
	data->env = (t_bucket *)ft_calloc(data->table_size, sizeof(t_bucket));
	if (!data->env)
		return (false);
	i = -1;
	while(envp[++i])
	{
		if (h_add(data->env, data->table_size, ft_strdup(envp[i])) == false)
		{
			h_clear_all(&(data->env), data->table_size);
			return (false);
		}
	}
	return (true);
}