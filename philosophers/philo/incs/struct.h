/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:35:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 15:58:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_fork
{
	bool			state;
	pthread_mutex_t	mutex;
}t_fork;

typedef struct s_info
{
	int				num_philo;
	int				num_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	uint64_t		time_start;
	t_fork			*fork;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	check_eat;
	pthread_mutex_t	check_end;
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

#endif