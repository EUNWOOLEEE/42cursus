/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:38:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:04:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	env_init(t_data *data, char **envp)
{
	int		i;
	int		j;
	t_list	*new;

	i = -1;
	while (envp[++i])
	{
		j = 0;
		while(envp[i][j] != '=')
			j++;
		new = ft_lstnew();
		new->env_key = ft_substr(envp[i], 0, j);
		new->env_value = ft_substr(envp[i], j + 1, ft_strlen(&envp[i][j + 1]));
		ft_lstadd_back(&data->envs, new);
	}
	return (true);
}

void	env_print(t_data *data)
{
	t_list	*cur;

	cur = data->envs;
	while (cur)
	{
		printf("%s=%s\n", cur->env_key, cur->env_value);
		cur = cur->next;
	}
}

t_list	*env_search(t_data *data, char *key)
{
	t_list	*cur;

	cur = data->envs;
	while (cur)
	{
		if (!ft_strncmp(cur->env_key, key, ft_strlen(key) + 1))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

bool	env_remove(t_data *data, char *key)
{
	t_list	*env;

	env = env_search(data, key);
	if (!env)
		return (false);
	env->pre->next = env->next;
	ft_lstdelone(env);
	return (true);
}

// char	**env_to_array()
// {

// }