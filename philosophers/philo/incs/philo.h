/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 17:54:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_fork
{
	bool			state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat;
}t_fork;

typedef struct s_info
{
	int				num_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
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
bool		start(t_philo *philo, t_info *info);
void		*routine(void *arg);
void		check_end(t_philo *philo, t_info *info);
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);
void		get_time(uint64_t *time);
void		pass_time(uint64_t time);
bool		print_error(char *str);
bool		print_state(t_philo *philo, t_info *info, char *str);
void		*ft_calloc(size_t count, size_t size);
uint64_t	ft_atoi(char *str, bool *state);
bool		all_free(t_philo **philo, t_info **info);

#endif