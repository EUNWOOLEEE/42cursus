/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 12:34:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	lexer(t_data *data);

bool	lexer(t_data *data)
{
	int			i;
	t_token		*token;

	token = token_create();
	if (!token)
		return (NULL);
	i = -1;
	while (data->input[++i])
	{
		if (data->input[i] == '|' || data->input[i] == '<' || data->input[i] == '>')
		{
			if (token->str)
			{
				if (token_add_list(&data->tokens, token, true) == false)
					return (false);
			}
			if (tokenizer(data, &token, &i) == false)
				return (false);
		}
		else if (data->input[i] == '\'' || data->input[i] == '\"')
		{
			if (tokenizer(data, &token, &i) == false)
				return (false);
		}
		else if (data->input[i] == ' ' || data->input[i] == '\t')
		{
			if (token->str)
			{
				if (token_add_list(&data->tokens, token, true) == false)
					return (false);
			}
		}
		else if (data->input[i] == '$')
			expand(data->input, token, &i, data, false);
		else
			token->str = ft_strncat(token->str, &data->input[i], 1);
	}
	if (token->str && *(token->str))
		token_add_list(&data->tokens, token, false);
	return (true);
}
