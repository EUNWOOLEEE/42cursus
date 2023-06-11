/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 07:35:56 by eunwolee         ###   ########.fr       */
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
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>

t_philo		*init(int argc, char **argv);
void		unlink_sem();
void		start(t_philo *philo, t_info *info);
void		routine(t_philo *philo, t_info *info);
void		check_end_main(t_info *info);
bool		check_end_philo(t_philo *philo, t_info *info, bool print);
bool		take_fork(t_philo *philo, t_info *info);;
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);
uint64_t	get_time(void);
bool		pass_time(t_philo *philo, t_info *info, uint64_t time);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(char *str);
bool		ft_mutex_unlock(t_philo *philo, t_info *info, char *mode);
bool		print_error(char *str);
bool		all_free(t_philo **philo, t_info **info);

char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);


#endif