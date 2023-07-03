/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 14:21:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	tokenize(char *input, t_token **token, int *i, t_list**head);

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

t_list	*lexer(char *input)
{
	int	i;
	t_list	*head;
	t_token	*token;

	i = -1;
	head = 0;
	token = new_token();
	if (!token)
		return (NULL);
	while (input[++i])
	{
		// printf("%d, %s\n", i, &input[i]);
		if (input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i] == '\'' || input[i] == '\"')
		{
			if (token->str)
			{
				add_token_to_list(&head, token); // 함수로 잘 합쳐보기
				token = new_token();
				if (!token)
					return (NULL);
			}
			tokenize(input, &token, &i, &head);
		}
		else if (input[i] == ' ')
		{
			if (token->str)
			{
				add_token_to_list(&head, token);
				token = new_token();
				if (!token)
					return (NULL);
			}
		}
		else
			token->str = ft_strncat(token->str, &input[i], 1);
	}
	if (*(token->str))
		add_token_to_list(&head, token);
	return (head);
}

bool	tokenize(char *input, t_token **token, int *i, t_list**head)
{
	if (input[*i] == '|')
	{
		(*token)->type = T_PIPE;
		(*token)->str = ft_strdup("");
	}
	else if (input[*i] == '\"')
	{
		if (double_quote(input, *token, i) == false)
			return (false);
	}
	else if (input[*i] == '\'')
	{
		if (single_quote(input, *token, i) == false)
			return (false);
	}
	else if (input[*i] == '>' || input[*i] == '<')
	{
		(*token)->type = T_REDIRECT;
		if (input[*i + 1] == input[*i])
		{
			(*token)->str = ft_strncat((*token)->str, &input[*i], 2);
			*i += 2;
		}
		else
		{
			(*token)->str = ft_strncat((*token)->str, &input[*i], 1);
			*i += 1;
		}
	}
	else if (input[*i] == '\0')
		(*token)->type = T_NULL;
	add_token_to_list(head, *token);
	*token = new_token();
	if (!*token)
		return (false);
	return (true);
}
