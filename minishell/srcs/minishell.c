/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/04 08:53:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_list	*list;
	// t_node	*root;
	char	*input;
	t_data	*data;
	
	(void)argc;
	(void)argv;
	init(&data, envp);
	//loop 시작 후 gnl로 읽고, input을 lexer에 전달해서 parsing
	input = ft_strdup("cat << end > | grep \"abc\" > test | cat -a -e >> test.txt");
	list = lexer(input);

	//print env in hash
	for(int i=0; envp[i]; i++)
	{
		int key = h_make_key(envp[i]);
		printf("key: %d, value: %s\n", key, h_search(data->env, data->table_size, key));
	}

	//print token
	t_list *tmp = list;
	while (tmp)
	{
		printf("%d, %s\n", tmp->token->type, tmp->token->str);
		tmp = tmp->next;
	}
	return (0);
}