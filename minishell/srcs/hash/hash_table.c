/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/04 07:45:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int				h_get_idx(int table_size, int key);
bool			h_add(t_bucket *table, int table_size, char *value);
char			*h_search(t_bucket *table, int table_size, int key);
static int		h_make_key(char *str);
static t_node	*h_create_node(char *value);

int	h_get_idx(int table_size, int key)
{
	return (key % table_size);
}

bool	h_add(t_bucket *table, int table_size, char *value)
{
	int	h_idx;
	t_node	*new;
	
	if (!value)
		return (false);
	new = h_create_node(value);
	if (!new)
		return (false);
	if (h_search(table, table_size, new->key))
		return (false); //Overlapped Key
	h_idx = h_get_idx(table_size, new->key);
	if (table[h_idx].size)
		new->next = table[h_idx].root;
	table[h_idx].root = new;
	table->size++;
}

char	*h_search(t_bucket *table, int table_size, int key)
{
	int		h_idx;
	t_node	*cur;

	h_idx = h_get_idx(table_size, key);
	cur = table[h_idx].root;
	while (cur)
	{
		if (cur->key == key)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

static int	h_make_key(char *str)
{
	int	key;

	key = 0;
	while (*str)
		key += (int)*str;
	return (key);
}

static t_node	*h_create_node(char *value)
{
	t_node	*new;
	int		key;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	key = h_make_key(value);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
