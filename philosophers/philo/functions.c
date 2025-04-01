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
	int	fork_num;

	fork_num = phi->num_philo - num;
	if (phi->num_philo == table->num_philos && num == 0)
		fork_num = 0;
	pthread_mutex_unlock(&table->forks[fork_num]);
	print_status(phi->num_philo, table, 5);
	return (1);
}

int	philo_take_fork(t_philo *phi, t_data *table, int num)
{
	int	fork_num;

	fork_num = phi->num_philo - num;
	if (phi->num_philo == table->num_philos && num == 0)
		fork_num = 0;
	pthread_mutex_lock(&table->forks[fork_num]);
	print_status(phi->num_philo, table, 0);
	return (1);
}

void	philo_eating(t_philo *phi, t_data *table)
{
	philo_take_fork(phi, table, 0); // esq
	if (iam_alive(phi, phi->table))
		philo_take_fork(phi, table, 1); // dir
	else
	{
		philo_release_fork(phi, table, 0); // esq
		return ;
	}
	gettimeofday(&phi->time_last_eaten, NULL);
	print_status(phi->num_philo, table, 1);
	usleep(table->tt_eat * 1000);
	philo_release_fork(phi, table, 0); // esq
	philo_release_fork(phi, table, 1); // dir
	phi->times_eaten++;
	return ;
}

void	philo_sleeping(t_philo *phi, t_data *table)
{
	print_status(phi->num_philo, table, 2);
	usleep(table->tt_sleep * 1000);
	return ;
}

void	philo_thinking(t_philo *phi, t_data *table)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	print_status(phi->num_philo, table, 3);
	// printf("phi->time_last_eaten: %dms\n", (int)(phi->time_last_eaten.tv_usec / 1000));
	// printf("table->tt_die: %d \\ time_math(phi->time_last_eaten, tv) %d\n", table->tt_die, time_math(phi->time_last_eaten, tv));
	usleep(table->tt_die - time_math(phi->time_last_eaten, tv));
	return ;
}

void	philo_dead(t_philo *phi, t_data *table)
{
	phi->table->philo_dead = 1;
	print_status(phi->num_philo, table, 4);
	return ;
}
