/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:37 by asalek            #+#    #+#             */
/*   Updated: 2022/03/21 20:40:08 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<pthread.h>
# include<unistd.h>
# include<stdlib.h>
# include<sys/time.h>

# define EATING 1
# define NOT_EATING 0

typedef struct s_arg
{
	int				phil_nb;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_must_eat;
	unsigned int	time;
	pthread_mutex_t	mutex;
	int				nb_philo_eat;
	int				died_of_starving;
}	t_args;

typedef struct s_philo
{
	int				id;
	unsigned int	could_die;
	pthread_t		t_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	t_args			*arg;
	int				eat_max_nb;
	int				state;
	int				eat_number;
}	t_philo;

void			ft_usleep(unsigned int t);
void			*check_stamina(void *philo);
unsigned int	get_time(void);
void			ft_putstr_modified(char *str, int id, t_args *arg);
void			activities(t_philo *philosopher);
int				ft_atoi(const char	*str);

#endif
