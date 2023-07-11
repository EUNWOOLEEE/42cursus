/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:38:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 12:00:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	env_print(t_data *data);
t_list	*env_search(t_data *data, char *key);
bool	env_remove(t_data *data, char *key);

void	env_print(t_data *data)
{
	t_list	*cur;

	cur = data->envs;
	while (cur)
	{
		printf("%s\n", cur->env);
		cur = cur->next;
	}
}

t_list	*env_search(t_data *data, char *key)
{
	char	*tmp;
	t_list	*cur;

	tmp = ft_strncat(key, "=", 1);
	cur = data->envs;
	while (cur)
	{
		if (!ft_strncmp(cur->env, tmp, ft_strlen(tmp)))
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

//이거 execve 이후에 free하는 함수 만들어야하나?(더블포인터만 해제하면 됨) 아니면 바로 리턴값을 execve에 보내도 되나?(data 구조체에 안 담고)
//execve에서 자동으로 해제되는거면 모든 환경변수들을 그냥 가리키게 하지말고 복제해야되나?
char	**env_to_array(t_data *data)
{
	t_list	*cur;
	char	**array;
	int		i;
	int		cnt;

	cnt = ft_lstsize(data->envs);
	array = (char **)ft_calloc(cnt, sizeof(char *));
	if (!array)
		return (NULL);
	i = -1;
	cur = data->envs;
	while(++i < cnt)
	{
		array[i] = cur->env;
		if (!array[i])
		{
			while (i--)
				free(array[i]);
			return (NULL);
		}
		cur = cur->next;
	}
	return (array);
}

//배열에 넣은 환경변수 출력용 임시 변수
void	env_array_print(t_data *data)
{
	char **array = env_to_array(data);

	for(int i=0; array[i]; i++)
		printf("%s\n", array[i]);
}
