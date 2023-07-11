/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:46:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 12:01:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	find_next_squote(char *input, int i)
{
	while (input[i] != '\'' && input[i] != '\0')
	{
		if (input[i] == '\\' && input[i + 1] == '\'')
			i++;
		i++;
	}
	if (input[i] == '\0')
		return (false);
	return (true);
}

bool	find_next_dquote(char *input, int i)
{
	while (input[i] != '\"' && input[i] != '\0')
	{
		if (input[i] == '\\' && input[i + 1] == '\"')
			i++;
		i++;
	}
	if (input[i] == '\0')
		return (false);
	return (true);
}

bool single_quote(char *input, t_token *token, int *i)
{
	*i += 1;
	if (find_next_squote(input, *i) == false)
		token->str = ft_strncat(token->str, "\'", 1);
	while (input[*i] != '\'' && input[*i] != '\0')
	{
		if (input[*i] == '\\' && input[*i + 1] == '\'')
		{
			token->str = ft_strncat(token->str, "\\\'", 1);
			*i += 1;
		}
		else
			token->str = ft_strncat(token->str, &input[*i], 1);
		if (!token->str)
			return (false);
		*i += 1;
	}
	if (token->str == NULL)
		token->str = ft_strdup("");
	if (input[*i] == '\0')
		*i -= 1;
	return (true);
}

bool double_quote(char *input, t_token *token, int *i, t_data *data)
{
	*i += 1;
	if (find_next_dquote(input, *i) == false)
		token->str = ft_strncat(token->str, "\"", 1);
	while (input[*i] != '\"' && input[*i] != '\0')
	{
		if (input[*i] == '\\' && input[*i + 1] == '\"')
		{
			token->str = ft_strncat(token->str, "\\\"", 1);
			*i += 1;
		}
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
	if (input[*i] == '\0')
		*i -= 1;
	return (true);
}

bool	expand(char *input, t_token *token, int *i, t_data *data, bool quote)
{
	char	*name;
	t_list	*tmp;
	
	*i += 1;
	name = NULL;
	tmp = ft_lstlast(data->tokens);
	if (tmp && tmp->token->redirect_type == T_HEREDOC)
	{
		token->str = ft_strncat(token->str, "$", 1);
		*i -= 1;
		return (true);
	}
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
	tmp = env_search(data, name);
	if (!tmp)
	{
		token->str = ft_strdup("$");
		token->str = ft_strncat(token->str, name, ft_strlen(name));
		if (!token->str)
			return (false);
	}
	else
	{
		int j = 0;
		while (tmp->env[j] != '=')
			j++;
		token->str = ft_strncat(token->str, &tmp->env[j + 1], ft_strlen(&tmp->env[j + 1]));
		if (!token->str)
			return (false);
	}
	free(name);
	return (true);
}