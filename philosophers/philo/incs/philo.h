/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:47:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/04 18:14:34 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef unsigned long long ULL;

typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philo
{
	pthread_t	num;
	ULL			time_die;
	ULL			time_eat;
	ULL			time_sleep;
}	t_philo;

typedef struct s_info
{
	int		num_philo;
	ULL		time_die;
	ULL		time_eat;
	ULL		time_sleep;
	int		num_eat;
	t_philo	*philos;
}	t_info;

t_info *init(int argc, char **argv);
ULL		ft_atoull(char *str);

#endif