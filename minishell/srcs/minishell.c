/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/16 20:33:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	// atexit(check_leak);
	
	(void)argc;
	(void)argv;
	init(&data, envp);

	char *str = get_next_line(0);
	data->input = ft_substr(str, 0, ft_strlen(str) - 1); //-1 개행 떼기
	if (lexer(data) == FALSE || syntax(data) == FALSE)
		return (0); //free하고 다시 input 받기
	parser(data);

	print_token(data);
	printf("\n\n");
	tree_print(data->root);
	
	all_free(data);
	return (0);
}
