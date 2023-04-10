/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/09 17:34:53 by eunwolee         ###   ########.fr       */
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

typedef struct s_elements
{
	int fd1;
	int fd2;
	int fd[2];
	pid_t pid;
	char **cmd1;
	char **cmd2;
	char **path;
}t_elements;

#endif