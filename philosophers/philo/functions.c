/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/17 19:50:20 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* print_status(phi->num_philo, table, "has released a fork"); */
int	philo_release_fork(t_philo *phi, t_data *table, int num)
{
	if (phi->num_philo == table->num_philos && num == 0)
		pthread_mutex_unlock(&table->forks[0]);
	else
		pthread_mutex_unlock(&table->forks[phi->num_philo - num]);
	// print_status(phi->num_philo, table, "has released a fork");
	return (1);
}

int	philo_take_fork(t_philo *phi, t_data *table, int num)
{
	if (phi->num_philo == table->num_philos && num == 0)
		pthread_mutex_lock(&table->forks[0]);
	else
		pthread_mutex_lock(&table->forks[phi->num_philo - num]);

	pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "has taken a fork");
	pthread_mutex_unlock(&table->philo_dead_mutex);
	return (1);
}
void philo_eating2(t_philo *phi, t_data *table)
{
    printf("DEBUG: Philo %d starting to eat\n", phi->num_philo);

    philo_take_fork(phi, table, 0);
    if (iam_alive(phi, phi->table))
        philo_take_fork(phi, table, 1);
    else
    {
        philo_release_fork(phi, table, 0);
        return;
    }

	pthread_mutex_lock(&phi->time_last_eaten_mutex);
	gettimeofday(&phi->time_last_eaten, NULL);
	pthread_mutex_unlock(&phi->time_last_eaten_mutex);

	pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is eating");
	pthread_mutex_unlock(&table->philo_dead_mutex);

    printf("DEBUG: Philo %d about to sleep during eating\n", phi->num_philo);
    precise_sleep(phi->time_last_eaten, table->tt_eat, phi);
    printf("DEBUG: Philo %d finished eating, releasing forks\n", phi->num_philo);

    philo_release_fork(phi, table, 0);
    philo_release_fork(phi, table, 1);

	pthread_mutex_lock(&phi->times_eaten_mutex);
	phi->times_eaten++;
	pthread_mutex_unlock(&phi->times_eaten_mutex);

    printf("DEBUG: Philo %d completed eating cycle\n", phi->num_philo);
}

void	philo_eating(t_philo *phi, t_data *table)
{
	// struct timeval	now;

	philo_take_fork(phi, table, 0);
	if (iam_alive(phi, phi->table))
		philo_take_fork(phi, table, 1);
	else
	{
		philo_release_fork(phi, table, 0);
		return ;
	}
	pthread_mutex_lock(&phi->time_last_eaten_mutex);
	gettimeofday(&phi->time_last_eaten, NULL);
	pthread_mutex_unlock(&phi->time_last_eaten_mutex);

	pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is eating");
	pthread_mutex_unlock(&table->philo_dead_mutex);

	precise_sleep(phi->time_last_eaten, table->tt_eat, phi);
	philo_release_fork(phi, table, 0);
	philo_release_fork(phi, table, 1);

	pthread_mutex_lock(&phi->times_eaten_mutex);
	phi->times_eaten++;
	pthread_mutex_unlock(&phi->times_eaten_mutex);
	return ;
}

void	philo_sleeping(t_philo *phi, t_data *table)
{
	struct timeval	start;

	gettimeofday(&start, NULL);

	pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is sleeping");
	pthread_mutex_unlock(&table->philo_dead_mutex);

	precise_sleep(start, table->tt_sleep, phi);
	return ;
}

void	philo_thinking(t_philo *phi, t_data *table)
{
	pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is thinking");
	pthread_mutex_unlock(&table->philo_dead_mutex);
	// usleep(1000);
	return ;
}
