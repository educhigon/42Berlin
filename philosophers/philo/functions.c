/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/04/01 20:14:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_release_fork(t_philo *phi, t_data *table, int num)
{
	if (phi->num_philo == table->num_philos && num == 0)
		pthread_mutex_unlock(&table->forks[0]);
	else
		pthread_mutex_unlock(&table->forks[phi->num_philo - num]);
	print_status(phi->num_philo, table, "has released a fork");
	return (1);
}

int	philo_take_fork(t_philo *phi, t_data *table, int num)
{
	if (phi->num_philo == table->num_philos && num == 0)
		pthread_mutex_lock(&table->forks[0]);
	else
		pthread_mutex_lock(&table->forks[phi->num_philo - num]);
	print_status(phi->num_philo, table, "has taken a fork");
	return (1);
}

void	philo_eating(t_philo *phi, t_data *table)
{
	philo_take_fork(phi, table, 0);
	if (iam_alive(phi, phi->table))
		philo_take_fork(phi, table, 1);
	else
	{
		philo_release_fork(phi, table, 0);
		return ;
	}
	gettimeofday(&phi->time_last_eaten, NULL);
	print_status(phi->num_philo, table, "is eating");
	precise_sleep(phi->time_last_eaten, table->tt_eat, phi);
	philo_release_fork(phi, table, 0);
	philo_release_fork(phi, table, 1);
	phi->times_eaten++;
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
	print_status(phi->num_philo, table, "is thinking");
	return ;
}
