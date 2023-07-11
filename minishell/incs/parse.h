/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:53:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:21:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

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

typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	t_token			*token;
	char			*env_key;
	char			*env_value;
}t_list;

# include "struct.h"

t_token	*new_token();
bool	add_token_to_list(t_list **head, t_token *token);
bool 	single_quote(char *input, t_token *token, int *i);
bool	double_quote(char *input, t_token *token, int *i, t_data *data);
bool	lexer(t_data *data);
bool	expand(char *input, t_token *token, int *i, t_data *data, bool quote);

#endif