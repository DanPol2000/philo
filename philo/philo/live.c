/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:29:17 by chorse            #+#    #+#             */
/*   Updated: 2022/04/29 12:19:21 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*live(void *arg)
{
	t_philo	*args;

	args = arg;
	pthread_mutex_lock(args->time);
	args->time_start = ft_time();
	args->start_eat = args->time_start;
	pthread_mutex_unlock(args->time);
	// if (args->num % 2 == 0)
	// 	usleep(500);
	while (args->cycles)
	{
		usleep(300);
		if (args->must_eat != -1)
		{
			pthread_mutex_lock(args->num_times);
			args->cycles--;
			pthread_mutex_unlock(args->num_times);
		}
		eating(args);
		if (args->cycles == 0)
			break ;
		sleeping(args);
	}
	return (NULL);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_m);
	pthread_mutex_lock(philo->print);
	printf("%lld %d has taken a fork\n", \
	ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_m);
	pthread_mutex_lock(philo->print);
	printf("%lld %d has taken a fork\n", \
	ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
	pthread_mutex_lock(philo->print);
	printf("%lld %d is eating\n", \
	ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->time);
	philo->start_eat = ft_time();
	pthread_mutex_unlock(philo->time);
	ft_sleep(philo->time_eat);
	pthread_mutex_unlock(philo->left_fork_m);
	pthread_mutex_unlock(philo->right_fork_m);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is sleeping\n", ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_sleep(philo->time_sleep);
	pthread_mutex_lock(philo->print);
	printf("%lld %d is thinking\n", ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
}
