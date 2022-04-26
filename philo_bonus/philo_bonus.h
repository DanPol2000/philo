/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:49:14 by ysachiko          #+#    #+#             */
/*   Updated: 2022/04/26 18:05:52 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_data
{
	int				number;
	int				id;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*general;
	int				*children_pids;
	long long		zero_time;
	long long		last_meal;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat;
	int				cycles;
	int				father_pid;
}				t_data;

int			ft_init_data(int argc, char **argv, t_data *data);
int			ft_init_sem(t_data *data);
long long	ft_time(void);
void		ft_sleep(long long msec);
int			ft_atoi(const char *str);
int			ft_init_philo(char **argv, t_data *data);
void		ft_define_cycles_numb(t_data *data);
void		ft_action(t_data *data);
void    	eating(t_data *data);
void    	sleeping(t_data *data);
void		ft_print_msg(t_data *data, char msg);
void		update_time(t_data *data);
void		monitoring(t_data *data);
void		*moni(void *arg);
void		ft_cleaning(t_data *data);
void		wait_philos(t_data *data);
void		exit_all(t_data *data);

#endif
