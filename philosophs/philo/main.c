/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:48:45 by chorse            #+#    #+#             */
/*   Updated: 2022/04/22 17:32:46 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_data			data;
	pthread_t		monitoring;

	i = 0;
	if (ft_init_data(argc, argv, &data))
	{
		write(2, "invalid value\n", 15);
		return (1);
	}
	while (i < data.number)
	{
		if (pthread_create(&data.thread[i], 0, live, &data.philo[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&monitoring, NULL, moni, &data) != 0)
		return (1);
	if (pthread_join(monitoring, NULL) != 0)
		return (1);
	return (0);
}

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = (long)tv.tv_sec * 1000 + (long)(tv.tv_usec / 1000);
	return (res);
}
