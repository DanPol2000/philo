/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:32:39 by chorse            #+#    #+#             */
/*   Updated: 2022/04/26 19:28:28 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sit(t_data *data)
{
	long long curTime;

	curTime = ft_time();
	while (curTime < data->zero_time + 200)
	{
		usleep(10);
		curTime = ft_time();
	}
}

void	update_time(t_data *data)
{
	data->zero_time = ft_time();
	data->last_meal = data->zero_time;
}

void initProcess(t_data *data)
{
	pid_t pid;

	data->id = 0;
	update_time(data);
	while (data->id < data->number)
	{
		pid = fork();
		if (pid == -1)
		{
			printf("ERROR_PROCESS INIT");
			exit (0);
		}
		if (pid == 0)
		{
			ft_sit(data);
			update_time(data);
			monitoring(data);
			update_time(data);
			ft_action(data);
			// break;
		}
		data->children_pids[data->id] = pid;
		data->id++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int				i;
	// pthread_t		monitoring;

	i = 0;
	// monitoring = NULL;
	if (ft_init_data(argc, argv, &data))
	{
		write(2, "invalid value\n", 15);
		return (1);
	}
	if (ft_init_philo(argv, &data))
	{
		write(2, "invalid value\n", 15);
		return (1);
	}
	initProcess(&data);
	wait_philos(&data);
	ft_cleaning(&data);
	return (0);
}
