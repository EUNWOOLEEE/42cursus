/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 11:55:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

bool	init(t_data **data, char **envp)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		return (false);
	if (env_init(*data, envp) == false)
	{
		ft_lstclear(&(*data)->envs);
		return (false);
	}
	return (true);
}

bool	env_init(t_data *data, char **envp)
{
	int		i;
	t_list	*new;

	i = -1;
	while (envp[++i])
	{
		new = ft_lstnew();
		if (!new)
			return (false);
		new->env = ft_strdup(envp[i]);
		if (!new->env)
			return (false);
		ft_lstadd_back(&data->envs, new);
	}
	return (true);
}