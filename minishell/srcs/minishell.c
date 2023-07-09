/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/10 06:45:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data	*data;
	
	(void)argc;
	(void)argv;
	init(&data, envp);
	//loop 시작 후 gnl로 읽고, input을 lexer에 전달해서 parsing
	// data->input = ft_strdup("cat << end > a | grep o\"hello\"\"world\" > $TEST | cat -a -e >> txt | echo \"a\"b\"c\" \"$a\"");
	data->input = ft_strdup("ca$a'def'");
	lexer(data);

	//print env in hash
	// for(int i=0; envp[i]; i++)
	// {
	// 	int cnt=0;
	// 	while(envp[i][cnt] != '=')
	// 		cnt++;
	// 	int key = h_make_key(ft_substr(envp[i], 0, cnt));
	// 	printf("env: %s, key: %d, h_idx: %d, value: %s\n", envp[i], key, h_func(data->table_size, key), h_search(data->env, data->table_size, key));
	// }

	//print token
	t_list *tmp = data->tokens;
	while (tmp)
	{
		printf("%d, %s\n", tmp->token->type, tmp->token->str);
		tmp = tmp->next;
	}
	return (0);
}