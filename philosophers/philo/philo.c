/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 09:30:32 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-29 09:30:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_func(void *arg)
{
	t_philo	*phi;

	phi = (t_philo *)arg;
	while (iam_alive(phi, phi->table))
	{
		philo_thinking(phi, phi->table);
		if (iam_alive(phi, phi->table))
			philo_eating(phi, phi->table);
		else
			return (NULL);
		philo_sleeping(phi, phi->table);
	}
	return (NULL);
}

void	create_philos(t_philo *phi, int i, t_data *table)
{
	phi->num_philo = i + 1;
	phi->time_last_eaten = table->dinner_start;
	phi->times_eaten = 0;
	phi->table = table;
	pthread_create(&phi->philo_thread, NULL, thread_func, phi);
	return ;
}

int	setup_table(t_data *table, int ac, char **av)
{
	gettimeofday(&table->dinner_start, NULL);
	table->philos = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (table->philos == NULL)
		return (0);
	table->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (table->forks == NULL)
		return (0);
	table->num_philos = ft_atoi(av[1]);
	table->tt_die = ft_atoi(av[2]);
	table->tt_eat = ft_atoi(av[3]);
	table->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->num_must_eat = ft_atoi(av[5]);
	else
		table->num_must_eat = -1;
	pthread_mutex_init(&table->mprint, NULL);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	table;

	if (!check_input(ac, av)) 
		return (0);
	if (!setup_table(&table, ac, av))
	{
		free_data(&table);
		return (0);
	}
	i = 0;
	while (i < table.num_philos)
	{
		pthread_mutex_init(&table.forks[i], NULL);
		create_philos(&table.philos[i], i, &table);
		usleep(5);
		i++;
	}
	i = 0;
	while (i < table.num_philos)
	{
		pthread_join(table.philos[i].philo_thread, NULL);
		i++;
	}
	free_data(&table);
	return (0);
}
