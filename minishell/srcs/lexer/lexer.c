/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:31:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	tokenize(t_data *data, t_token **token, int *i);

t_token	*new_token()
{
	t_token	*token;
	
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL); //list clear
	token->type = T_WORD;
	return (token);
}

bool	add_token_to_list(t_list **head, t_token *token)
{
	t_list	*new;
	
	new = ft_lstnew();
	if (!new)
		return (false);
	new->token = token;
	ft_lstadd_back(head, new);
	return (true);
}

bool	lexer(t_data *data)
{
	int			i;
	t_token		*token;

	token = new_token();
	if (!token)
		return (NULL);
	i = -1;
	while (data->input[++i])
	{
		// printf("%d, %s\n", i, &data->input[i]);
		if (data->input[i] == '|' || data->input[i] == '<' || data->input[i] == '>')
		{
			if (token->str)
			{
				add_token_to_list(&data->tokens, token); // 함수로 잘 합쳐보기
				token = new_token();
				if (!token)
					return (false);
			}
			if (tokenize(data, &token, &i) == false)
				return (false);
		}
		else if (data->input[i] == '\'' || data->input[i] == '\"')
		{
			if (tokenize(data, &token, &i) == false)
				return (false);
		}
		else if (data->input[i] == ' ' || data->input[i] == '\t')
		{
			if (token->str)
			{
				add_token_to_list(&data->tokens, token);
				token = new_token();
				if (!token)
					return (false);
			}
		}
		else if (data->input[i] == '$')
			expand(data->input, token, &i, data, false);
		else
			token->str = ft_strncat(token->str, &data->input[i], 1);
	}
	if (token->str && *(token->str))
		add_token_to_list(&data->tokens, token);
	return (true);
}

bool	tokenize(t_data *data, t_token **token, int *i)
{
	if (data->input[*i] == '|')
	{
		(*token)->type = T_PIPE;
		(*token)->str = ft_strdup("|");
	}
	else if (data->input[*i] == '\"')
	{
		if (double_quote(data->input, *token, i, data) == false)
			return (false);
	}
	else if (data->input[*i] == '\'')
	{
		if (single_quote(data->input, *token, i) == false)
			return (false);
	}
	else if (data->input[*i] == '<' || data->input[*i] == '>')
	{
		(*token)->type = T_REDIRECT;
		if (data->input[*i] == '<')
		{
			if (data->input[*i + 1] == '<')
				(*token)->redirect_type = T_HEREDOC;
			else
				(*token)->redirect_type = T_INPUT;
		}
		else
		{
			if (data->input[*i + 1] == '>')
				(*token)->redirect_type = T_APPEND;
			else
				(*token)->redirect_type = T_OUTPUT;
		}
		//문자열이 필요할까?
		if (data->input[*i + 1] == data->input[*i])
		{
			(*token)->str = ft_strncat((*token)->str, &data->input[*i], 2);
			*i += 1;
		}
		else
			(*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
	}
	if ((data->input[*i] == '\'' || data->input[*i] == '\"') && (data->input[*i + 1] != ' ' && data->input[*i + 1] != '\t'))
		return (true);
	add_token_to_list(&data->tokens, *token);
	*token = new_token();
	if (!*token)
		return (false);
	return (true);
}
