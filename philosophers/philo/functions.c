/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/22 16:44:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

int	philo_release_fork(t_philo *phi, t_data *table, int num)
{
	// if (phi->num_philo == table->num_philos && num == 0)
	// 	pthread_mutex_unlock(&table->forks[0]);
	// else
	// 	pthread_mutex_unlock(&table->forks[phi->num_philo - num]);
	// return (1);

		int fork_index;

	if (phi->num_philo == table->num_philos && num == 0)
			fork_index = 0;
	else
			fork_index = phi->num_philo - num;

	// printf("Philo %d UNLOCKING fork %d (num=%d)\n", phi->num_philo, fork_index, num);
	pthread_mutex_unlock(&table->forks[fork_index]);
	// if (num)
	// 	print_status(phi->num_philo, table, "has released fork LEFT");
	// else
	// 	print_status(phi->num_philo, table, "has released fork RIGHT");

	return (1);
}

int	philo_take_fork(t_philo *phi, t_data *table, int num)
{
	int fork_index;
	// char str[20];
	// strcpy(str, "has taken fork 0");

	if (phi->num_philo == table->num_philos && num == 0)
		fork_index = 0;
	else
		fork_index = phi->num_philo - num;

	// str[15] = (char)('0' + fork_index);
	// printf("Philo %d trying MUTEX at address %p (fork %d)\n",
	// 	phi->num_philo, &table->forks[fork_index], fork_index);

	pthread_mutex_lock(&table->forks[fork_index]);

	// printf("Philo %d LOCKED MUTEX at address %p (fork %d)\n",
	// 	phi->num_philo, &table->forks[fork_index], fork_index);

	// pthread_mutex_lock(&table->philo_dead_mutex);
	// printf("Fork: %d\n",phi->num_philo - num );
	// if (num)
	// 	print_status(phi->num_philo, table, "has taken a fork Left");
	// else
	// 	print_status(phi->num_philo, table, "has taken a fork Right");
	print_status(phi->num_philo, table, "has taken fork");
	// pthread_mutex_unlock(&table->philo_dead_mutex);
	return (1);
}

void	philo_eating(t_philo *phi, t_data *table)
{
	int fork;

	fork = 1; // LEFT
	if(phi->num_philo %2 == 0)
		fork = 0; // RIGHT

	philo_take_fork(phi, table, fork);
	philo_take_fork(phi, table, !fork);

	pthread_mutex_lock(&phi->time_last_eaten_mutex);
	gettimeofday(&phi->time_last_eaten, NULL);
	pthread_mutex_unlock(&phi->time_last_eaten_mutex);
	// pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is eating");
	// pthread_mutex_unlock(&table->philo_dead_mutex);
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
	// pthread_mutex_lock(&table->philo_dead_mutex);
	print_status(phi->num_philo, table, "is sleeping");
	// pthread_mutex_unlock(&table->philo_dead_mutex);
	precise_sleep(start, table->tt_sleep, phi);
	return ;
}

void	philo_thinking(t_philo *phi, t_data *table)
{
	// pthread_mutex_lock(&table->philo_dead_mutex);
	if(table->num_philos % 2 == 0)
	{
		if (table->tt_die - table->tt_eat - table->tt_sleep > 100)
			usleep((phi->num_philo % 10) * 2000);
		print_status(phi->num_philo, table, "is thinking");
	}
	else
	{
		if (table->tt_die - 2*table->tt_eat - table->tt_sleep > 100)
			usleep((phi->num_philo % 10) * 2000);
		print_status(phi->num_philo, table, "is thinking");
	}


	// print_status(phi->num_philo, table, "is thinking");
	// pthread_mutex_unlock(&table->philo_dead_mutex);
	// usleep((phi->num_philo % 10) * 1000);
	return ;
}
