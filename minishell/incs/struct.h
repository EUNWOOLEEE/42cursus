/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:42:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 08:31:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_type
{
	T_NULL,
	T_PIPE,
	T_WORD,
	T_REDIRECT
}t_type;

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

typedef struct s_list
{
	t_token			*token;
	struct s_list	*next;
}t_list;

// typedef struct s_node
// {
// 	t_token			*token;
// 	struct s_node	*left_child;
// 	struct s_node	*right_child;
// }t_node;

// typedef struct s_env
// {
// 	int	key;
// 	char *value;
// }	t_env;

#endif