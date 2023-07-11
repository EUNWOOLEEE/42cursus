/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 11:43:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef enum e_token_type
{
	T_NULL,
	T_PIPE,
	T_WORD,
	T_REDIRECT,
	T_CMD,
	T_ARG,
	T_INPUT,
	T_OUTPUT,
	T_HEREDOC,
	T_APPEND
}t_token_type;

typedef struct s_token
{
	int		type;
	int		redirect_type;
	char	*str;
}	t_token;

//tokens와 envs에서 통용되는 리스트 구조체
typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	t_token			*token;
	char			*env;
}t_list;

typedef struct s_leaf
{
	struct s_leaf	*left_child;
	struct s_leaf	*right_child;
	bool			exist;
	t_token			*token;
}t_leaf;

//최종 가공된 데이터들 담은 구조체
typedef struct s_data
{
	int			table_size;
	char		*input;
	t_list		*tokens;
	t_list		*envs;
	char		**env_array;
	// t_leaf		*root;
}	t_data;

#endif