/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:33:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 15:06:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define NOT_USING 0
# define USING 1

# define USAGE "usage: ./philo <number_of_philosophers>\n \
	<time_to_die> <time_to_eat> <time_to_sleep>\n \
	[number_of_times_each_philosopher_must_eat]"
# define MALLOC "Malloc failure"
# define THREAD "Create thread failure"
# define MUTEX "Mutex init failure"
# define TIME "Time must be at least 0"
# define NUMBER "Number must be at least 1"

# define FORK "%s%llu %d has taken a fork%s\n"
# define EAT "%s%llu %d is eating%s\n"
# define SLEEP "%s%llu %d is sleeping%s\n"
# define THINK "%s%llu %d is thinking%s\n"
# define DIE "%s%llu %d died%s\n"

#endif