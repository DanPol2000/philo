/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:02:19 by chorse            #+#    #+#             */
/*   Updated: 2022/04/16 15:44:21 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	data->number = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->number);
	if (!data->philo)
		return (1);
	if (argc == 6)
		data->number_of_times = ft_atoi(argv[5]);
	else
		data->number_of_times = -1;
	if (ft_init_mut(data))
		return (1);
	while (i < data->number)
	{
		ft_init_philo(&data->philo[i], data, argv, i);
		i++;
	}
	data->thread = malloc(sizeof(pthread_t) * data->number);
	if (!data->thread)
		return (1);
	return (0);
}

int	ft_init_mut(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number);
	if (!data->forks)
		return (1);
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		return (1);
	data->time = malloc(sizeof(pthread_mutex_t));
	if (!data->time)
		return (1);
	while (i < data->number)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(data->print, NULL);
	pthread_mutex_init(data->time, NULL);
	return (0);
}

void	ft_init_philo(t_philo *philo, t_data *data, char **argv, int i)
{
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->number_of_times = data->number_of_times;
	philo->num = data->number;
	philo->last_time_eat = 0;
	philo->print = data->print;
	philo->id = i + 1;
	philo->time = data->time;
	philo->left_fork_m = &data->forks[i];
	philo->right_fork_m = &data->forks[(i + 1) % data->number];
}