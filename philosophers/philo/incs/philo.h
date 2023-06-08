/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/08 15:42:37 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./color.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define NOT_USING 0
# define USING 1

# define USAGE "usage: ./philo <number_of_philosophers>\n \
	<time_to_die> <time_to_eat> <time_to_sleep>\n \
	[number_of_times_each_philosopher_must_eat]"
# define MALLOC "Malloc failure"
# define MUTEX "Mutex init failure"
# define TIME "Time must be at least 0"
# define NUM "Number must be at least 1"
// # define FORK "\033[38;2;179;200;144m%llu %d has taken a fork\n\033[0m"
// # define EAT "\033[38;2;255;170;201m%llu %d is eating\n\033[0m"
// # define SLEEP "\033[38;2;255;231;155m%llu %d is sleeping\n\033[0m"
// # define THINK "\033[38;2;115;187;201m%llu %d is thinking\n\033[0m"
// # define DIE "\033[38;2;228;165;255m%llu %d died\n\033[0m"

# define FORK "%s%llu %d has taken a fork\n%s"
# define EAT "%s%llu %d is eating\n%s"
# define SLEEP "%s%llu %d is sleeping\n%s"
# define THINK "%s%llu %d is thinking\n%s"
# define DIE "%s%llu %d died\n%s"

typedef struct s_fork
{
	bool			state;
	pthread_mutex_t	mutex;
}t_fork;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	uint64_t		time_start;
	t_fork			*fork;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	bool			scheduling;
	bool			end;
	bool			error;
	int				eat_cnt;
}t_info;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id_philo;
	int			first;
	int			second;
	int			eat_cnt;
	uint64_t	time_last_eat;
	t_info		*info;
}t_philo;

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