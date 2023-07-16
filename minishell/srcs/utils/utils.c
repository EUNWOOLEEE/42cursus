/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:40:44 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/16 20:18:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_bool	error_back_readline(t_data *data, char *str, int error_code);
void	program_error_exit(char *str);
void	all_free(t_data *data);

//input 관련 에러일 때 사용
t_bool	error_back_readline(t_data *data, char *str, int error_code)
{
	printf("%s\n", str);
	data->error_code = error_code;
	return (FALSE);
}

//system 관련 에러일 때
void	program_error_exit(char *str)
{
	perror(str);
	exit(errno);
}

void	all_free(t_data *data)
{
	free(data->input);
	ft_lstclear(&data->tokens);
	ft_lstclear(&data->envs);
	tree_clear(data->root);
	free(data);
}