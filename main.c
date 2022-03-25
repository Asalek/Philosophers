/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:24 by asalek            #+#    #+#             */
/*   Updated: 2022/03/16 15:14:29 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *philo)
{
	int			i;
	pthread_t	t_id;
	t_philo		*philosopher;

	philosopher = (t_philo *)philo;
	i = 0;
	philosopher->eat_max_nb = 0;
	philosopher->eat_number = 0;
	philosopher->could_die = philosopher->arg->t_die + philosopher->arg->time;
	pthread_create(&t_id, NULL, &check_stamina, philosopher);
	pthread_detach(t_id);
	while (i < philosopher->arg->nb_must_eat
		|| !(philosopher->arg->nb_must_eat))
	{
		activities(philosopher);
		i++;
	}
	philosopher->eat_max_nb = 1;
	return (NULL);
}

void	link_threads(t_philo *t, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->phil_nb)
	{
		t[i].id = i + 1;
		t[i].arg = args;
		if (i == args->phil_nb - 1)
			t[i].next_fork = &t[0].fork;
		else
			t[i].next_fork = &t[i + 1].fork;
		i++;
	}
}

t_philo	*create_philos(t_args *t)
{
	t_philo	*phil;
	int		i;

	i = 0;
	phil = malloc(sizeof(t_philo) * t->phil_nb);
	if (!phil)
		return (printf("Allocation failed\n"), NULL);
	while (i < t->phil_nb)
		pthread_mutex_init(&phil[i++].fork, NULL);
	i = -1;
	link_threads(phil, t);
	t->time = get_time();
	while (++i < t->phil_nb)
	{
		if (pthread_create(&phil[i].t_id, NULL, &func, &phil[i]) != 0)
			return (printf("Pthread_creat Failed \n"), NULL);
		usleep(20);
	}
	i = -1;
	while (++i < t->phil_nb)
		pthread_detach(phil[i].t_id);
	return (phil);
}

int	take_args(int ac, t_args *t, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Chigau !\n"), 1);
	t->phil_nb = ft_atoi(av[1]);
	t->t_die = ft_atoi(av[2]);
	t->t_eat = ft_atoi(av[3]);
	t->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		t->nb_must_eat = ft_atoi(av[5]);
	else
		t->nb_must_eat = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_args	t;
	t_philo	*p;
	int		i;

	i = 0;
	t.died_of_starving = 0;
	t.nb_philo_eat = 0;
	pthread_mutex_init(&t.mutex, NULL);
	take_args(ac, &t, av);
	p = create_philos(&t);
	if (!p)
		return (0);
	while (t.died_of_starving == 0)
	{
		if (t.nb_philo_eat == t.phil_nb)
			break ;
	}
	free(p);
	return (0);
}
