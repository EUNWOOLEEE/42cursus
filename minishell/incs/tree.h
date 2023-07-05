/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:52:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/06 08:38:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef enum e_redirect_type
{
	R_HEREDOC,
	R_INPUT,
	R_OUTPUT,
	R_APPEND
}t_redirect_type;

//트리로 다시
typedef struct s_cmd
{
	char			*str; //cmd && arg
	struct s_cmd	*next;
}t_cmd;

//트리로 다시
typedef struct s_redirect
{
	int					type;
	char				*str; //filename || limiter
	struct s_redirect	*next;
}t_redirect;

typedef struct s_status
{
	bool		exist; //pipe || redirect 존재 유무
	t_cmd		*cmd;
	t_redirect	*re;
}t_status;


typedef struct s_node
{
	t_token			*token;
	struct s_node	*left_child;
	struct s_node	*right_child;
}t_node;

#endif