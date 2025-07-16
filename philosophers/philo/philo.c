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

void	philo_seq(t_philo *phi)
{
	if (phi->num_philo % 2 == 0)
	{
		while (iam_alive(phi, phi->table))
		{
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
	return ;
}

void	*thread_func(void *arg)
{
	t_philo	*phi;

	phi = (t_philo *)arg;
	if (phi->table->num_philos == 1)
	{
		philo_take_fork(phi, phi->table, 0);
		while (iam_alive(phi, phi->table))
			continue ;
		philo_release_fork(phi, phi->table, 0);
		return (NULL);
	}
	usleep(phi->num_philo);
	philo_seq(phi);
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

void	*global_monitor(void *arg)
{
	struct timeval	now;
	t_data			*tb;
	int				i;
	int				havent_eaten_enough;

	tb = (t_data *)arg;
	havent_eaten_enough = 0;
	while (!tb->philo_dead && !havent_eaten_enough)
	{
		gettimeofday(&now, NULL);
		usleep(1);
		i = -1;
		while (++i < tb->num_philos && !tb->philo_dead)
		{
			if (tb->philos[i].times_eaten == tb->num_must_eat)
				havent_eaten_enough = 1;
			else
				havent_eaten_enough = 0;
			if (time_math(tb->philos[i].time_last_eaten, now) > tb->tt_die)
			{
				usleep(1);
				if (time_math(tb->philos[i].time_last_eaten, now) > tb->tt_die)
				{
					print_status(tb->philos[i].num_philo, tb, "died");
					tb->philo_dead = 1;
				}
				// printf("%d\n", (int)(((now.tv_sec - tb->philos[i].time_last_eaten.tv_sec) * 1000
				// + (now.tv_usec - tb->philos[i].time_last_eaten.tv_usec) / 1000)));
				// printf("%d\n", tb->tt_die);
				// print_status(tb->philos[i].num_philo, tb, "died");
				// tb->philo_dead = 1;
			}
		}
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	monitor;
	int			i;
	t_data		table;

	if (!check_input(ac, av))
		return (0);
	if (!setup_table(&table, ac, av))
		return (free_data(&table));
	i = -1;
	while (++i < table.num_philos)
	{
		pthread_mutex_init(&table.forks[i], NULL);
		create_philos(&table.philos[i], i, &table);
		precise_sleep(table.dinner_start,
			(table.num_philos / 10), &table.philos[i]);
	}
	pthread_create(&monitor, NULL, global_monitor, &table);
	i = -1;
	while (++i < table.num_philos)
		pthread_join(table.philos[i].philo_thread, NULL);
	pthread_join(monitor, NULL);
	free_data(&table);
	return (0);
}
