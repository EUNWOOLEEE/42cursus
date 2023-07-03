/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:26 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/04 07:46:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

typedef struct s_node
{
	int				key;
	char			*value;
	struct s_node	*next;
}	t_node;

//배열로 만들어서 사용
typedef struct s_bucket
{
	t_node	*root;
	int		size;
}	t_bucket;

/*hash_table*/
int		h_get_idx(int table_size, int key);
bool	h_add(t_bucket *table, int table_size, char *value);
char	*h_search(t_bucket *table, int table_size, int key);

/*hash_remove*/
bool	h_remove_one(t_bucket *table, int table_size, int key);
void	h_clear_all(t_bucket **table, int table_size);

#endif