/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/31 17:19:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	philo_take_fork(t_philo *phi, t_data *table)
{
	pthread_mutex_lock(&table->mprint);
	print_status(phi->num_philo, table, 0);
	pthread_mutex_unlock(&table->mprint);
    return ;
}

void	philo_eating(t_philo *phi, t_data *table)
{
	struct timeval tv;
    gettimeofday(&tv, NULL);

	pthread_mutex_lock(&table->mprint);
	print_status(phi->num_philo, table, 1);
	pthread_mutex_unlock(&table->mprint);

	usleep(table->tt_eat);
	phi->time_last_eaten = tv;
    return ;
}

void	philo_sleeping(t_philo *phi, t_data *table)
{
	pthread_mutex_lock(&table->mprint);
	print_status(phi->num_philo, table, 2);
	pthread_mutex_unlock(&table->mprint);

	usleep(table->tt_sleep);
    return ;
}

void	philo_thinking(t_philo *phi, t_data *table)
{
	pthread_mutex_lock(&table->mprint);
	print_status(phi->num_philo, table, 3);
	pthread_mutex_unlock(&table->mprint);

    return ;
}

void	philo_dead(t_philo *phi, t_data *table)
{
	pthread_mutex_lock(&table->mprint);
	print_status(phi->num_philo, table, 4);
	pthread_mutex_unlock(&table->mprint);
	return ;
}


