/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 10:49:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

// 환경변수 키값만 저장해둘 리스트 만들기
int				hash_make_key(char *name);
int				hash_func(int table_size, int key);
bool			hash_add(t_bucket *table, int table_size, char *name, char *value);
char			*hash_search(t_bucket *table, int table_size, int key);
static t_node	*hash_create_node(char *name, char *value);

int	hash_make_key(char *name)
{
	int			i;
	int			j;
	long long	mid;
	long long	key;

	i = -1;
	key = 0;
	while (name[++i])
	{
		j = i;
		mid = 1;
		while (j--)
			mid = (mid * 31) % MODULAR;
		key += name[i] * mid;
	}
	return (key % MODULAR);
}

int	hash_func(int table_size, int key)
{
	return (key % table_size);
}

bool	hash_add(t_bucket *table, int table_size, char *name, char *value)
{
	int		h_idx;
	t_node	*new;
	
	if (!value)
		return (false);
	new = hash_create_node(name, value);
	free(name);
	if (!new)
	{
		free(value);
		return (false);
	}
	if (hash_search(table, table_size, new->key)) //Overlapped Key
	{
		free(new->value);
		free(new);
		return (false);
	}
	h_idx = hash_func(table_size, new->key);
	if (table[h_idx].size)
		new->next = table[h_idx].root;
	table[h_idx].root = new;
	table[h_idx].size++;
	return (true);
}

char	*hash_search(t_bucket *table, int table_size, int key)
{
	int		h_idx;
	t_node	*cur;

	h_idx = hash_func(table_size, key);
	cur = table[h_idx].root;
	while (cur)
	{
		if (cur->key == key)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

static t_node	*hash_create_node(char* e_key, char *value)
{
	t_node	*new;
	int		key;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	key = hash_make_key(e_key);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

// void print_env(char **envp, t_data *data)
// {
// 	for(int i=0; envp[i]; i++)
// 	{
// 		int cnt=0;
// 		while(envp[i][cnt] != '=')
// 			cnt++;
// 		int key = h_make_key(ft_substr(envp[i], 0, cnt));
// 		printf("env: %s, key: %d, h_idx: %d, value: %s\n", envp[i], key, h_func(data->table_size, key), h_search(data->env, data->table_size, key));
// 	}
// }