/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:52:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/08 15:00:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "parse.h"
typedef enum e_redirect_type
{
	R_HEREDOC,
	R_INPUT,
	R_OUTPUT,
	R_APPEND
}t_redirect_type;

typedef struct s_leaf
{
	t_token			*token;
	bool			exist;
	struct s_leaf	*left_child;
	struct s_leaf	*right_child;
}t_leaf;

t_leaf	*t_create_leaf(t_token *token, bool exist);
bool	t_add_left(t_leaf *parent, t_leaf *new);
bool	t_add_right(t_leaf *parent, t_leaf *new);

#endif