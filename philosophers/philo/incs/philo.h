/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 07:32:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./msg.h"
# include "./color.h"
# include "./struct.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

t_philo		*init(int argc, char **argv);
bool		init_info(int argc, char **argv, t_info *info);
bool		init_mutex(t_info *info);
void		init_philo(t_philo *philo, t_info *info);
void		start(t_philo *philo, t_info *info);
void		*routine(void *arg);
void		check_end_main(t_info *info);
void		check_end_philo(t_philo *philo, t_info *info);
bool		take_fork(t_philo *philo, t_info *info);;
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);
uint64_t	get_time();
void		pass_time(t_philo *philo, t_info *info, uint64_t time);
bool		ft_mutex_unlock(pthread_mutex_t *a, pthread_mutex_t *b, pthread_mutex_t *c, int num);
bool		print_error(char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(char *str);
bool		all_free(t_philo **philo, t_info **info);

#endif