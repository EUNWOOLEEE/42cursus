/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 16:46:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./color.h"
# include "./struct.h"
# include "./message.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

/*init*/
t_philo		*init(int argc, char **argv);
void		destroy_mutex(t_info *info);

/*start*/
void		start(t_philo *philo, t_info *info);
void		*routine(void *arg);

/*check*/
void		check_end_main(t_info *info);
bool		check_end_philo(t_philo *philo, t_info *info, bool print);

/*act*/
bool		take_fork(t_philo *philo, t_info *info);;
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);

/*time*/
uint64_t	get_time(void);
bool		pass_time(t_philo *philo, t_info *info, uint64_t time);

/*utils*/
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(char *str);
bool		check_arg(int argc, char **argv);
bool		print_error(char *str);
bool		all_free(t_philo **philo, t_info **info);

#endif