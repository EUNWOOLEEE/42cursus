/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/05 16:24:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int				h_make_key(char *e_key);
int				h_func(int table_size, int key);
bool			h_add(t_bucket *table, int table_size, char *e_key, char *e_value);
char			*h_search(t_bucket *table, int table_size, int key);
static t_node	*h_create_node(char *e_key, char *e_value);

int	h_make_key(char *e_key)
{
	int			i;
	int			j;
	long long	mid;
	long long	key;

	i = -1;
	key = 0;
	while (e_key[++i])
	{
		j = i;
		mid = 1;
		while (j--)
			mid = (mid * 31) % MODULAR;
		key += e_key[i] * mid;
	}
	return (key % MODULAR);
}

int	h_func(int table_size, int key)
{
	return (key % table_size);
}

bool	h_add(t_bucket *table, int table_size, char *e_key, char *e_value)
{
	int	h_idx;
	t_node	*new;
	
	if (!e_value)
		return (false);
	new = h_create_node(e_key, e_value);
	free(e_key);
	if (!new)
	{
		free(e_value);
		return (false);
	}
	if (h_search(table, table_size, new->key)) //Overlapped Key
	{
		free(new->value);
		free(new);
		return (false);
	}
	h_idx = h_func(table_size, new->key);
	if (table[h_idx].size)
		new->next = table[h_idx].root;
	table[h_idx].root = new;
	table[h_idx].size++;
	return (true);
}

char	*h_search(t_bucket *table, int table_size, int key)
{
	int		h_idx;
	t_node	*cur;

	h_idx = h_func(table_size, key);
	cur = table[h_idx].root;
	while (cur)
	{
		if (cur->key == key)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

static t_node	*h_create_node(char* e_key, char *e_value)
{
	t_node	*new;
	int		key;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	key = h_make_key(e_key);
	new->key = key;
	new->value = e_value;
	new->next = NULL;
	return (new);
}
