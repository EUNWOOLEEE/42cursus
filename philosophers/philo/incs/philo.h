/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:47:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/15 08:40:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

# define LEFT 
# define RIGHT
typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_info
{
	int				num_philo;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	int				num_eat;
	uint64_t		time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_bool			end;
}	t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	num;
	int			eat_cnt;
	int			left;
	int			right;
	uint64_t	last_eat_time;
	t_info		*info;
}	t_philo;

t_philo		*init(int argc, char **argv);
uint64_t	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
t_bool		get_cur_time(uint64_t *time);
t_bool		print_time(t_philo *philo, t_info *info, char *state);
t_bool		start(t_philo *philo, t_info *info);
t_bool		eating(t_philo *philo, t_info *info);
void		sleeping(t_philo *philo, t_info *info);
void		thinking(t_philo *philo, t_info *info);

#endif