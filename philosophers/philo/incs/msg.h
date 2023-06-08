/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:33:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 06:34:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define NOT_USING 0
# define USING 1

# define USAGE "usage: ./philo <number_of_philosophers>\n \
	<time_to_die> <time_to_eat> <time_to_sleep>\n \
	[number_of_times_each_philosopher_must_eat]"
# define MALLOC "Malloc failure"
# define MUTEX "Mutex init failure"
# define TIME "Time must be at least 0"
# define NUM "Number must be at least 1"

# define FORK "%s%llu %d has taken a fork\n%s"
# define EAT "%s%llu %d is eating\n%s"
# define SLEEP "%s%llu %d is sleeping\n%s"
# define THINK "%s%llu %d is thinking\n%s"
# define DIE "%s%llu %d died\n%s"

#endif