/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/29 21:37:54 by eunwolee         ###   ########.fr       */
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

typedef struct s_info
{
	int				num_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	end_lock;
	bool			end;
	bool			error;
	uint64_t		time_to_start;
}t_info;

typedef struct s_philo
{
	pthread_t	thread_id;
	int			philo_id;
	int			left;
	int			right;
	int			eat_cnt;
	uint64_t	time_last_eat;
	t_info		*info;
}t_philo;

t_philo		*init(int argc, char **argv);
bool		init_info(int argc, char **argv, t_info *info);
bool		init_mutex(t_info *info);
bool		init_philo(t_philo *philo, t_info *info);
bool		start(t_philo *philo, t_info *info);
void		*routine(void *arg);
bool		check_end(t_philo *philo, t_info *info);
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);
bool		get_time(uint64_t *time);
bool		pass_time(uint64_t time);
void		print_usage();
bool		print_state(t_philo *philo, t_info *info, char *str);
void		*ft_calloc(size_t count, size_t size);
uint64_t	ft_atoi(char *str, bool *state);
char		*ft_strdup(const char *s1);


#endif