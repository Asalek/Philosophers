/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:45 by asalek            #+#    #+#             */
/*   Updated: 2022/03/16 15:14:47 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + str[i] - 48;
		i++;
	}
	return (count * sign);
}

void	activities(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher -> fork);
	ft_putstr_modified("has taken a fork", philosopher->id, philosopher->arg);
	pthread_mutex_lock(philosopher -> next_fork);
	ft_putstr_modified("has taken a fork", philosopher->id, philosopher->arg);
	philosopher->state = EATING;
	philosopher->eat_number += 1;
	ft_putstr_modified("is eating", philosopher->id, philosopher->arg);
	philosopher->could_die = get_time() + philosopher->arg->t_die;
	ft_usleep(philosopher->arg->t_eat * 1000);
	pthread_mutex_unlock(&philosopher -> fork);
	pthread_mutex_unlock(philosopher -> next_fork);
	philosopher->state = NOT_EATING;
	if (philosopher->eat_number >= philosopher->arg->nb_must_eat
		&& philosopher->arg->nb_must_eat != 0)
		return ;
	ft_putstr_modified("is sleeping", philosopher->id, philosopher->arg);
	ft_usleep(philosopher->arg->t_sleep * 1000);
	ft_putstr_modified("is thinking", philosopher->id, philosopher->arg);
}

void	ft_putstr_modified(char *str, int id, t_args *arg)
{
	unsigned int	ms;

	pthread_mutex_lock(&arg->mutex);
	ms = get_time() - arg->time;
	printf("%u %d %s\n", ms, id, str);
	pthread_mutex_unlock(&arg->mutex);
}

unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*check_stamina(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	while (philosopher->arg->died_of_starving != 1)
	{
		if (get_time() >= philosopher->could_die
			&& philosopher->state != EATING)
		{
			ft_putstr_modified(" died", philosopher->id, philosopher->arg);
			pthread_mutex_lock(&philosopher->arg->mutex);
			philosopher->arg->died_of_starving = 1;
			break ;
		}
		else if (philosopher->eat_max_nb == 1)
		{
			philosopher->arg->nb_philo_eat += 1;
			break ;
		}
	}
	return (NULL);
}
