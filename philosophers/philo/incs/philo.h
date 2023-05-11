/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:47:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/11 16:20:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long long ULL;
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
	ULL				time_die;
	ULL				time_eat;
	ULL				time_sleep;
	int				num_eat;
	ULL				time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	num;
	int			eat_cnt;
	int			left;
	int			right;
	ULL			last_eat_time;
	t_info		*info;
}	t_philo;

t_philo *init(int argc, char **argv);
ULL		ft_atoull(char *str);
void	*ft_calloc(size_t count, size_t size);
t_bool	get_cur_time(ULL *time);
t_bool	print_time(t_philo *philo, t_info *info, char *state);
t_bool	start(t_philo *philo, t_info *info);

#endif