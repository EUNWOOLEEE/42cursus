/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:20:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 12:21:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

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