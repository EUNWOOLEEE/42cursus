/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:48:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 10:49:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

bool	init_env(t_data *data, char **envp)
{
	int	i;
	int	cnt;

	data->table_size = 128; //2의 제곱근
	data->env = (t_bucket *)ft_calloc(data->table_size, sizeof(t_bucket));
	if (!data->env)
		return (false);
	i = -1;
	while(envp[++i])
	{
		cnt = 0;
		while(envp[i][cnt] != '=')
			cnt++;
		if (h_add(data->env, data->table_size, ft_substr(envp[i], 0, cnt), \
			ft_substr(envp[i], cnt + 1, ft_strlen(&envp[i][cnt + 1]))) == false)
		{
			h_clear_all(&(data->env), data->table_size);
			return (false);
		}
	}
	return (true);
}