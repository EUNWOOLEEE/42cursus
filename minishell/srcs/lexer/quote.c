/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:46:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 13:58:45 by eunwolee         ###   ########.fr       */
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

bool double_quote(char *input, t_token *token, int *i)
{
	*i += 1;
	while (input[*i] != '\"' && input[*i] != '\0')
	{
		if (input[*i] == '\\' && input[*i + 1] == '\"')
		{
			token->str = ft_strncat(token->str, &input[*i], 2);
			*i += 1;
		}
		// if (input[*i] == '$')
		// {
		// 	//expand
		// }
		else
			token->str = ft_strncat(token->str, &input[*i], 1);
		if (!token->str)
			return (false);
		*i += 1;
	}
	if (input[*i] == '\0')
		exit(1); //error
	return (true);
}