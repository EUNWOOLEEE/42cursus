/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:53:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/06 08:27:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum e_token_type
{
	T_NULL,
	T_PIPE,
	T_WORD,
	T_REDIRECT
}t_token_type;

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

bool	add_token_to_list(t_list **head, t_token *token);
bool 	single_quote(char *input, t_token *token, int *i);
bool	double_quote(char *input, t_token *token, int *i);
t_list	*lexer(char *input);

#endif