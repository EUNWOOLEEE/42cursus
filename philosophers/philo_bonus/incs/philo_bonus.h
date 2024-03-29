/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 20:49:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "./color.h"
# include "./struct.h"
# include "./message.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>

/*init*/
t_info		*init(int argc, char **argv);
void		unlink_sem(void);

/*start*/
void		start(t_info *info);

/*check*/
bool		check_full(t_info *info);
void		check_end_main(t_info *info);
bool		check_end_philo(t_info *info, bool print);

/*act*/
bool		take_fork(t_info *info);
bool		eating(t_info *info);
bool		sleeping(t_info *info);
bool		thinking(t_info *info);

/*time*/
uint64_t	get_time(void);
bool		pass_time(t_info *info, uint64_t time);

/*utils*/
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(char *str);
bool		check_arg(int argc, char **argv);
bool		print_error(char *str);
bool		all_free(t_info **info);

#endif