/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/13 18:34:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../Libft/libft.h"

# define S_IRUGO S_IRUSR|S_IRGRP|S_IROTH
# define P_READ 0
# define P_WRITE 1

typedef enum e_bool
{
	FALSE, TRUE
}t_bool;

typedef struct s_cmd
{
	int fd[2];
	pid_t pid;
	char **cmd_arg;
}t_cmd;

typedef struct s_data
{
	int infile;
	int outfile;
	int cmd_num;
	int cur_pid;
	char **path;
	t_cmd *cmd;
}t_data;

void	init_data(t_data **data, int argc, char **argv, char **envp);
void	print_error(char *error);

#endif