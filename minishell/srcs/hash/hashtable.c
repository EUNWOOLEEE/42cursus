/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 19:25:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	h_key_maker(char *str)
{
	int	key;

	key = 0;
	while (*str)
		key += (int)*str;
	return (key);
}

t_node	*h_create_node()
{
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	return (new);
}

bool	h_add_hash(t_bucket *table, int key)
{
	
}