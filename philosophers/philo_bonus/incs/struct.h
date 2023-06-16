/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:35:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 16:26:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>

typedef struct s_philo
{
	pid_t		*id_process;
	int			id_philo;
	int			eat_cnt;
	uint64_t	time_last_eat;
}t_philo;

typedef struct s_sem
{
	sem_t		*fork;
	sem_t		*start;
	sem_t		*print;
	sem_t		*check_eat;
}t_sem;

typedef struct s_info
{
	int			num_philo;
	int			num_must_eat;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	uint64_t	time_start;
	pid_t		monitor;
	t_philo		philo;
	t_sem		sem;
	bool		flag_error;
}t_info;


#endif