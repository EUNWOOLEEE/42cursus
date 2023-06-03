/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 19:50:22 by eunwolee         ###   ########.fr       */
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

# define MSG_USAGE "usage: ./philo <number_of_philosophers>\n \
	<time_to_die> <time_to_eat> <time_to_sleep>\n \
	[number_of_times_each_philosopher_must_eat]"
# define MSG_TIME "time must be at least 0"
# define MSG_NUM "number must be at least 1"
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE "died"

typedef struct s_fork
{
	bool			state;
	pthread_mutex_t	mutex;
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
	pthread_mutex_t	print;
	bool			end;
	bool			error;
	int				eat_cnt;
}t_info;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id_philo;
	int			left;
	int			right;
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