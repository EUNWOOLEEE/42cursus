/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/27 16:26:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define P_READ 0
# define P_WRITE 1
# define CHILD 0

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
	t_bool	heredoc;
	char	*limiter;
}t_data;

void	init_data(t_data **data, int argc, char **argv, char **envp);
t_bool	check_slash(char *cmd);
int		check_quote(char *str);
char	**split_quote(char *s, char c, int cnt);
int		cnt_len(char const *s, char c);
void	heredoc(t_data *data, int argc, char **argv);
void	execute_pipex(t_data *data, char **envp);
void	execute_cmd(char **path_lst, t_cmd cmd, char **envp);
void	wait_child(t_data *data);
void	get_pipe(t_data *data, int idx);
void	link_pipe(t_data *data, int cur, int pre);
void	close_pipe(t_data *data, int cur, int pre);
void	print_error(char *error);
void	free_data(t_data *data);

#endif