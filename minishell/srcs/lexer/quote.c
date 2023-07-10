/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:46:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/10 16:15:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool single_quote(char *input, t_token *token, int *i)
{
	*i += 1;
	while (input[*i] != '\'' && input[*i] != '\0')
	{
		token->str = ft_strncat(token->str, &input[*i], 1);
		if (!token->str)
			return (false);
		*i += 1;
	}
	if (token->str == NULL)
		token->str = ft_strdup("");
	// if (input[*i] == '\0')
	// 	exit(1); //error
	return (true);
}

bool double_quote(char *input, t_token *token, int *i, t_data *data)
{
	*i += 1;
	while (input[*i] != '\"' && input[*i] != '\0')
	{
		if (input[*i] == '$')
		{
			if (input[*i + 1] == '\'')
				token->str = ft_strncat(token->str, &input[*i], 1);
			else
				if (expand(input, token, i, data, true) == false)
					return (false);
		}
		else
			token->str = ft_strncat(token->str, &input[*i], 1);
		if (!token->str)
			return (false);
		*i += 1;
	}
	if (token->str == NULL)
		token->str = ft_strdup("");
	return (true);
}

bool	expand(char *input, t_token *token, int *i, t_data *data, bool quote)
{
	char	*name;
	char	*value;
	
	*i += 1;
	name = NULL;
	if (input[*i] == ' ' || input[*i] == '\t')
	{
		token->str = ft_strncat(token->str, "$", 1);
		token->str = ft_strncat(token->str, &input[*i], 1);
		if (quote == true)
			return (true);
		while (input[*i] == ' ' || input[*i] == '\t')
			*i += 1;
		*i -= 1;
		return (true);
	}
	if (input[*i] == '\'' || input[*i] == '\"')
	{
		*i -= 1 ;
		return (true);
	}
	if (input[*i] == '\0')
	{
		token->str = ft_strncat(token->str, "$", 1);
		return (true);
	}
	while (input[*i] != ' ' && input[*i] != '\t' && input[*i] != '\0' \
		&& input[*i] != '\'' && input[*i] != '\"')
	{
		name = ft_strncat(name, &input[*i], 1);
		if (!name)
			return (false);
		*i += 1;
	}
	*i -= 1;
	value = h_search(data->env, data->table_size, h_make_key(name));
	if (!value)
	{
		token->str = ft_strdup("");
		if (!token->str)
			return (false);
	}
	else
	{
		token->str = ft_strncat(token->str, value, ft_strlen(value));
		if (!token->str)
			return (false);
	}
	free(name);
	free(value);
	return (true);
}