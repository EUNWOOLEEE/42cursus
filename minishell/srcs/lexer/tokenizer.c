/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:26:13 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 12:36:34 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_token	*token_create();
bool	token_add_list(t_list **head, t_token *token, bool token_flag);

bool	tokenizer(t_data *data, t_token **token, int *i)
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
	if (token_add_list(&data->tokens, *token, true) == false)
		return (false);
	return (true);
}

t_token	*token_create()
{
	t_token	*token;
	
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL); //list clear
	token->type = T_WORD;
	return (token);
}

bool	token_add_list(t_list **head, t_token *token, bool token_flag)
{
	t_list	*new;
	
	new = ft_lstnew();
	if (!new)
		return (false);
	new->token = token;
	ft_lstadd_back(head, new);
	if (token_flag == true)
	{
		token = token_create();
		if (!token)
			return (false);
	}
	return (true);
}
