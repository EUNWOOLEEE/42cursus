/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:27:39 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/15 20:10:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

uint64_t	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
t_bool		get_cur_time(uint64_t *time);
t_bool		print_time(t_philo *philo, t_info *info, char *state);

uint64_t	ft_atoi(char *str)
{
	uint64_t	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	memset(tmp, 0, size * count);
	return (tmp);
}

t_bool	get_cur_time(uint64_t *time)
{
	struct timeval tv;

	if	(gettimeofday(&tv, NULL) == -1)
		return (FALSE);
	*time = (uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (TRUE);
}

t_bool	print_time(t_philo *philo, t_info *info, char *state)
{
	uint64_t	cur_time;

	if (get_cur_time(&cur_time) == FALSE)
	 	return (FALSE);
	if (pthread_mutex_lock(&info->print))
		return (FALSE);
	printf("%lld %d %s\n", cur_time - info->time_start, philo->id + 1, state);
	if (pthread_mutex_unlock(&info->print))
		return (FALSE);
	return (TRUE);
}

void	pass_time(uint64_t time)
{
	uint64_t	start;
	uint64_t	cur;

	get_cur_time(&start);
	get_cur_time(&cur);
	while (cur - start < time)
	{
		usleep(100);
		get_cur_time(&cur);
	}
}