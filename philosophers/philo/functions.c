/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/31 17:50:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_fork(t_philo *phi, t_data *table)
{
	print_status(phi->num_philo, table, 0);
	return ;
}

void	philo_eating(t_philo *phi, t_data *table)
{
	// struct timeval	tv;

	// while(!philo_take_fork(phi, table))
	// 	usleep(phi->tt_die / time_math(phi->time_last_eaten, tv))
	// gettimeofday(&tv, NULL);
	print_status(phi->num_philo, table, 1);
	usleep(table->tt_eat * 1000);
	gettimeofday(&phi->time_last_eaten, NULL);
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
	print_status(phi->num_philo, table, 3);
	printf("phi->time_last_eaten: %dms\n", (int)(phi->time_last_eaten.tv_usec / 1000));
	usleep((int)(phi->time_last_eaten.tv_usec / 1000 * (table->tt_die / 1000)));
	return ;
}

void	philo_dead(t_philo *phi, t_data *table)
{
	print_status(phi->num_philo, table, 4);
	return ;
}
