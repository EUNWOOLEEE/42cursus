/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:35:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 08:22:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>

typedef struct s_info
{
	int			num_philo;
	int			num_must_eat;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	uint64_t	time_start;
	sem_t		*fork;
	sem_t		*start;
	sem_t		*print;
	sem_t		*check_eat;
	sem_t		*check_end;
	bool		end;
	bool		error;
	int			eat_cnt;
}t_info;

typedef struct s_philo
{
	pid_t		id_process;
	int			id_philo;
	int			eat_cnt;
	uint64_t	time_last_eat;
}t_philo;

#endif