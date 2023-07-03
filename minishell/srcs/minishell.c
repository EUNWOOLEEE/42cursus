/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/03 12:49:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int main()
{
	t_list	*list;
	// t_node	*root;
	char	*input;
	
	//loop 시작 후 gnl로 읽고, input을 lexer에 전달해서 parsing
	input = ft_strdup("grep \"abc\" | cat -a -e");
	list = lexer(input);

	t_list *tmp = list;
	while (tmp)
	{
		printf("%d, %s\n", tmp->token->type, tmp->token->str);
		tmp = tmp->next;
	}
	return (0);
}