/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:46:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/10 07:00:08 by eunwolee         ###   ########.fr       */
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
	if (input[*i] == '\0')
		exit(1); //error
	return (true);
}

bool double_quote(char *input, t_token *token, int *i, t_data *data)
{
	*i += 1;
	while (input[*i] != '\"' && input[*i] != '\0')
	{
		if (input[*i] == '$')
		{
			//해당하는 환경변수로 치환
			//해당하는거 없으면 그냥 공백
			//달러만 들어오면 그냥 달러만 출력
			if (input[*i + 1] == '\"' || input[*i + 1] == ' ' || input[*i + 1] == '\t')
				token->str = ft_strncat(token->str, &input[*i], 1);
			else
				if (expand(input, token, i, data) == false)
					return (false);
		}
		else
			token->str = ft_strncat(token->str, &input[*i], 1);
		if (!token->str)
			return (false);
		*i += 1;
	}
	// if (input[*i] == '\0') //왜 넣은 거였지?
	// {
	// 	printf("a\n");
	// 	return (false);
	// }
		// exit(1); //error
	return (true);
}

bool	expand(char *input, t_token *token, int *i, t_data *data)
{
	char	*name;
	char	*value;
	
	*i += 1;
	name = NULL;
	while (input[*i] != ' ' && input[*i] != '\t' && input[*i] != '\"' && input[*i] != '\0'\
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
		token->str = ft_strncat(token->str, "$", 1);
		if (!token->str)
			return (false);
		token->str = ft_strncat(token->str, name, ft_strlen(name));
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