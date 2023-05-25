/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/25 19:15:29 by eunwolee         ###   ########.fr       */
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
	int			num_philo;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			num_must_eat;
	int			*fork;
	bool		print;
	bool		end;
	uint64_t	time_to_start;
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

void	print_usage();
bool	print_state(t_philo *philo, t_info *info, char *str);
void	*ft_calloc(size_t count, size_t size);
bool	ft_atoi(char *str, uint64_t *res);
bool	get_time(uint64_t *time);
bool	pass_time(uint64_t *time);


#endif