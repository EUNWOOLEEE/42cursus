/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:23:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void print_token(t_data *data)
{
	t_list *tmp = data->tokens;
	while (tmp)
	{
		printf("%d, %s\n", tmp->token->type, tmp->token->str);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_data	*data;
	
	(void)argc;
	(void)argv;
	init(&data, envp);

	//loop 시작 후 readline로 읽고, input을 lexer에 전달해서 parsing
	char *str = get_next_line(0);
	data->input = ft_substr(str, 0, ft_strlen(str) - 1); //개행 떼기
	lexer(data);

	print_token(data);
	return (0);
}