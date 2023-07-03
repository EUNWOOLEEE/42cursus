/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:07:26 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 19:25:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

typedef struct s_node
{
	int				key;
	char			*value;
	struct s_node	*hash;
}	t_node;

//배열로 만들어서 사용
typedef struct s_bucket
{
	t_node	*root;
	int		size;
}	t_bucket;

#endif