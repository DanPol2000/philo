/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:02:19 by chorse            #+#    #+#             */
/*   Updated: 2022/04/23 14:10:54 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	data->number = ft_atoi(argv[1]);
	if (data->number <= 0 || (argv[5] && ft_atoi(argv[5]) <= 0) || ft_atoi(argv[4]) <= 0 \
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[2]) <= 0)
		return (1);
	if (argc == 6)
		data->eat = ft_atoi(argv[5]);
	else
		data->eat = -1;
	if (ft_init_sem(data))
		return (1);
	return (0);
}

int	ft_init_sem(t_data *data)
{
	int	i;

	i = 0;
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->number);
	if (data->forks == SEM_FAILED)
		return (printf("%s\n", "Error: sem_open failed"));
	sem_unlink("forks");
	data->print = sem_open("messages", O_CREAT, S_IRWXU, 1);
	if (data->print == SEM_FAILED)
	{
		sem_close(data->forks);
		return (printf("%s\n", "Error: sem_open failed"));
	}
	sem_unlink("print");
	data->general = sem_open("general", O_CREAT, S_IRWXU, 1);
	if (data->general == SEM_FAILED)
	{
		sem_close(data->forks);
		sem_close(data->print);
		return (printf("%s\n", "Error: sem_open failed"));
	}
	sem_unlink("general");
	return (0);
}

int	ft_init_philo(char **argv, t_data *data)
{
	ft_define_cycles_numb(data);
	data->number = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->last_meal = 0;
	data->zero_time = ft_time();
	printf("%d\n", data->number);
	printf("%lld\n", data->zero_time * 1000);
	printf("%d\n", data->eat_time);
	printf("%d\n", data->eat);
	printf("%d\n", data->cycles);
	return (0);
}

void	ft_define_cycles_numb(t_data *data)
{
	if (data->eat != -1)
		data->cycles = data->eat;
	else
		data->cycles = 1;
}