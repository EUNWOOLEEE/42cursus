/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/17 18:39:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define P_READ 0
# define P_WRITE 1

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_cmd
{
	int		fd[2];
	pid_t	pid;
	t_bool	slash;
	char	**cmd_arg;
}t_cmd;

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		cmd_num;
	char	**path;
	t_cmd	*cmd;
	t_bool	here_doc;
}t_data;

void	init_data(t_data **data, int argc, char **argv, char **envp);
void	execute_pipex(t_data *data, char **envp);
void	execute_cmd(char **path_lst, t_cmd cmd, char **envp);
void	wait_child(t_data *data);
void	get_pipe(t_data *data, int idx);
void	link_pipe(t_data *data, int i);
void	close_pipe(t_data *data, int i);
void	print_error(char *error);
void	free_data(t_data *data);

#endif