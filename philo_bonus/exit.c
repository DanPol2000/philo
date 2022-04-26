/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:34:31 by chorse            #+#    #+#             */
/*   Updated: 2022/04/26 19:55:31 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    exit_all(t_data *data)
{
    int i;
    i = 0;
    while (i < data->number)
    {
        kill(data->children_pids[i], SIGKILL);
        i++;
    }
}
void    ft_cleaning(t_data *data)
{
    sem_close(data->forks);
    sem_close(data->print);
    sem_close(data->general);
    if (data->children_pids != NULL)
        free(data->children_pids);
}
void    wait_philos(t_data *data)
{
    int *stat_loc;
	
	stat_loc = malloc(sizeof(int));
    while (data->number--)
	{
		waitpid(-1, stat_loc, 0);
		if (*stat_loc == 256)
   		{
			exit_all(data);
			break ;
		}
	}
}
