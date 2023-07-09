/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/10 06:52:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	tokenize(t_data *data, t_token **token, int *i, t_list**head);

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
	
	new = ft_lstnew(token);
	if (!new)
		return (false);
	ft_lstadd_back(head, new);
	return (true);
}

bool	lexer(t_data *data)
{
	int	i;
	t_list	*head;
	t_token	*token;

	i = -1;
	head = 0;
	token = new_token();
	if (!token)
		return (NULL);
	while (data->input[++i])
	{
		// printf("%d, %s\n", i, &data->input[i]);
		if (data->input[i] == '|' || data->input[i] == '<' || data->input[i] == '>')
		{
			if (token->str)
			{
				add_token_to_list(&head, token); // 함수로 잘 합쳐보기
				token = new_token();
				if (!token)
					return (false);
			}
			if (tokenize(data, &token, &i, &head) == false)
				return (false);
		}
		else if (data->input[i] == '\'' || data->input[i] == '\"') // 논리적으로 맞는지 체크
		{
			if (tokenize(data, &token, &i, &head) == false)
				return (false);
		}
		else if (data->input[i] == ' ' || data->input[i] == '\t')
		{
			if (token->str)
			{
				add_token_to_list(&head, token);
				token = new_token();
				if (!token)
					return (false);
			}
		}
		else if (data->input[i] == '$')
		{
			if (data->input[i + 1] == '\"' || data->input[i + 1] == ' ' || data->input[i + 1] == '\t')
				token->str = ft_strncat(token->str, &data->input[i], 1);
			else
				expand(data->input, token, &i, data);
		}
		else
			token->str = ft_strncat(token->str, &data->input[i], 1);
	}
	if (*(token->str))
		add_token_to_list(&head, token);
	data->tokens = head;
	return (true);
}

bool	tokenize(t_data *data, t_token **token, int *i, t_list**head)
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
	else if (data->input[*i] == '>' || data->input[*i] == '<')
	{
		(*token)->type = T_REDIRECT;
		if (data->input[*i + 1] == data->input[*i])
		{
			(*token)->str = ft_strncat((*token)->str, &data->input[*i], 2);
			*i += 2;
		}
		else
		{
			(*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
			*i += 1;
		}
	}
	if ((data->input[*i] == '\'' || data->input[*i] == '\"') && (data->input[*i + 1] != ' ' && data->input[*i + 1] != '\t'))
		return (true);
	add_token_to_list(head, *token);
	*token = new_token();
	if (!*token)
		return (false);
	return (true);
}
