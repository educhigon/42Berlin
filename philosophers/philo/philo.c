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
	gettimeofday(&phi->time_last_eaten, NULL);
	if (phi->num_philo % 2 == 0)
	{
		while (iam_alive(phi, phi->table))
		{
			philo_eating(phi, phi->table);
			philo_sleeping(phi, phi->table);
			philo_thinking(phi, phi->table);
		}
	}
	else
	{
		while (iam_alive(phi, phi->table))
		{
			philo_sleeping(phi, phi->table);
			philo_thinking(phi, phi->table);
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
		pthread_mutex_lock(&phi->table->philo_dead_mutex);
		phi->table->philo_dead = 0;
		print_status(1, phi->table, "died");
		phi->table->philo_dead = 1;
		pthread_mutex_unlock(&phi->table->philo_dead_mutex);
		philo_release_fork(phi, phi->table, 0);
		return (NULL);
	}
	philo_seq(phi);
	return (NULL);
}

void	loop_philos(t_data *tb, int didnt_eat_all, struct timeval now, int died)
{
	int	i;

	i = -1;
	while (++i < tb->num_philos && !died)
	{
		pthread_mutex_lock(&tb->philos[i].times_eaten_mutex);
		pthread_mutex_lock(&tb->philos[i].time_last_eaten_mutex);
		if (tb->philos[i].times_eaten < tb->num_must_eat)
			didnt_eat_all = 0;
		if (time_math(tb->philos[i].time_last_eaten, now)
			> tb->tt_die && !didnt_eat_all)
		{
			print_status(tb->philos[i].num_philo, tb, "died");
			pthread_mutex_lock(&tb->philo_dead_mutex);
			tb->philo_dead = 1;
			pthread_mutex_lock(&tb->printing_allowed_mutex);
			tb->printing_allowed = 0;
			pthread_mutex_unlock(&tb->printing_allowed_mutex);
			died = 1;
			pthread_mutex_unlock(&tb->philo_dead_mutex);
		}
		pthread_mutex_unlock(&tb->philos[i].time_last_eaten_mutex);
		pthread_mutex_unlock(&tb->philos[i].times_eaten_mutex);
	}
}

void	*global_monitor(void *arg)
{
	struct timeval	now;
	t_data			*tb;
	int				havent_eaten_enough;

	tb = (t_data *)arg;
	while (1)
	{
		havent_eaten_enough = 1;
		if (tb->num_must_eat == -1)
			havent_eaten_enough = 0;
		usleep(1000);
		gettimeofday(&now, NULL);
		loop_philos(tb, havent_eaten_enough, now, 0);
		if (tb->philo_dead || havent_eaten_enough)
			break ;
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
		pthread_mutex_init(&table.forks[i], NULL);
	i = -1;
	while (++i < table.num_philos)
		create_philos(&table.philos[i], i, &table);
	pthread_create(&monitor, NULL, global_monitor, &table);
	i = -1;
	while (++i < table.num_philos)
		pthread_join(table.philos[i].philo_thread, NULL);
	pthread_join(monitor, NULL);
	free_data(&table);
	return (0);
}
