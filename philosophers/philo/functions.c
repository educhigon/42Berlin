/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/22 17:09:39 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

int	philo_release_fork(t_philo *phi, t_data *table, int num)
{
	int	fork_index;

	if (phi->num_philo == table->num_philos && num == 0)
		fork_index = 0;
	else
		fork_index = phi->num_philo - num;
	pthread_mutex_unlock(&table->forks[fork_index]);
	return (1);
}

int	philo_take_fork(t_philo *phi, t_data *table, int num)
{
	int	fork_index;

	if (phi->num_philo == table->num_philos && num == 0)
		fork_index = 0;
	else
		fork_index = phi->num_philo - num;
	pthread_mutex_lock(&table->forks[fork_index]);
	print_status(phi->num_philo, table, "has taken fork");
	return (1);
}

void	philo_eating(t_philo *phi, t_data *table)
{
	int	fork;

	fork = 1;
	if (phi->num_philo % 2 == 0)
		fork = 0;
	philo_take_fork(phi, table, fork);
	philo_take_fork(phi, table, !fork);
	pthread_mutex_lock(&phi->time_last_eaten_mutex);
	gettimeofday(&phi->time_last_eaten, NULL);
	pthread_mutex_unlock(&phi->time_last_eaten_mutex);
	print_status(phi->num_philo, table, "is eating");
	precise_sleep(phi->time_last_eaten, table->tt_eat, phi);
	philo_release_fork(phi, table, fork);
	philo_release_fork(phi, table, !fork);
	pthread_mutex_lock(&phi->times_eaten_mutex);
	phi->times_eaten++;
	pthread_mutex_unlock(&phi->times_eaten_mutex);
	return ;
}

void	philo_sleeping(t_philo *phi, t_data *table)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	print_status(phi->num_philo, table, "is sleeping");
	precise_sleep(start, table->tt_sleep, phi);
	return ;
}

void	philo_thinking(t_philo *phi, t_data *table)
{
	if (table->num_philos % 2 == 0)
	{
		if (table->tt_die - table->tt_eat - table->tt_sleep > 100)
			usleep((phi->num_philo % 10) * 2000);
		print_status(phi->num_philo, table, "is thinking");
	}
	else
	{
		if (table->tt_die - 2 * table->tt_eat - table->tt_sleep > 100)
			usleep((phi->num_philo % 10) * 2000);
		print_status(phi->num_philo, table, "is thinking");
	}
	return ;
}
