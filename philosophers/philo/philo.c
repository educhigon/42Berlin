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
	// usleep((phi->num_philo) * 1000);
	if (phi->table->num_philos == 1)
	{
		philo_take_fork(phi, phi->table, 0); // esq
		while(iam_alive(phi, phi->table))
			continue;
		philo_release_fork(phi, phi->table, 0); // esq
		return (NULL);
	}

	usleep(phi->num_philo);
	if (phi->num_philo % 2 == 0)
	{
		while (iam_alive(phi, phi->table))
		{
			// printf("phi->last_eaten: %ld", phi->time_last_eaten.tv_sec * 1000 + phi->time_last_eaten.tv_usec / 1000);
			if (iam_alive(phi, phi->table))
				philo_eating(phi, phi->table);
			if (iam_alive(phi, phi->table))
				philo_sleeping(phi, phi->table);
			if (iam_alive(phi, phi->table))
				philo_thinking(phi, phi->table);
		}
	}
	else
	{
		while (iam_alive(phi, phi->table))
		{
			if (iam_alive(phi, phi->table))
				philo_sleeping(phi, phi->table);
			if (iam_alive(phi, phi->table))
				philo_thinking(phi, phi->table);
			if (iam_alive(phi, phi->table))
				philo_eating(phi, phi->table);
		}
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
	table->num_philos = ft_atoi(av[1]);
	// printf("table->num_philos: %d\n", table->num_philos);
	table->tt_die = ft_atoi(av[2]);
	// printf("table->tt_die: %d\n", table->tt_die);
	table->tt_eat = ft_atoi(av[3]);
	// printf("table->tt_eat: %d\n", table->tt_eat);
	table->tt_sleep = ft_atoi(av[4]);
	// printf("table->tt_sleep: %d\n", table->tt_sleep);
	if (ac == 6)
	{
		table->num_must_eat = ft_atoi(av[5]);
		printf("table->num_must_eat: %d\n", table->num_must_eat);
	}
	table->philos = NULL;
	table->forks = NULL;
	table->philo_dead = 0;

	if (table->num_philos <=0 || table->tt_die <=0 || table->tt_eat <=0 || table->tt_sleep <=0 )
		return (0);
		
	gettimeofday(&table->dinner_start, NULL);
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos == NULL)
		return (0);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (table->forks == NULL)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) > 0)
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
		usleep(1);
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
