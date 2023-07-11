/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 06:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 06:56:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	hash_remove_one(t_bucket *table, int table_size, int key);
void	hash_clear_all(t_bucket **table, int table_size);

bool	hash_remove_one(t_bucket *table, int table_size, int key)
{
	int		h_idx;
	t_node	*pre;
	t_node	*cur;

	h_idx = hash_func(table_size, key);
	pre = NULL;
	cur = table[h_idx].root;
	while (cur)
	{
		if (cur->key == key)
		{
			if (!pre) //지우려는 노드가 루트 노드
				table[h_idx].root = cur->next;
			else if (pre && cur->next)
				pre->next = cur->next;
			table[h_idx].size--;
			free(cur->value);
			free(cur);
			return (true);
		}
		pre = cur;
		cur = cur->next;
	}
	return (false);
}

void	hash_clear_all(t_bucket **table, int table_size)
{
	int		i;
	t_node	*cur;
	t_node	*next;

	i = -1;
	while (++i < table_size)
	{
		cur = table[i]->root;
		while (cur)
		{
			next = cur->next;
			free(cur->value);
			free(cur);
			cur = next;
		}
	}
	free(*table);
	*table = NULL;
}
