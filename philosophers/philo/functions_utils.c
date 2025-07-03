/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 11:26:12 by edugonza          #+#    #+#             */
/*   Updated: 2025-04-16 11:26:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_sleep(struct timeval start, int benchmark, t_philo *phi)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (time_math(start, now) <= benchmark && phi)
		gettimeofday(&now, NULL);
}

void	print_status(int philo_num, t_data *table, char *str)
{
	struct timeval	tv;

	if (table->philo_dead)
		return ;
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&table->mprint);
	printf("{%dms} - [#%d] %s\n",
		time_math(table->dinner_start, tv), philo_num, str);
	pthread_mutex_unlock(&table->mprint);
	return ;
}

int	iam_alive(t_philo *phi, t_data *table)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (time_math(phi->time_last_eaten, now) > phi->table->tt_die
		&& phi->table->philo_dead != 1)
	{
		phi->table->philo_dead = 1;
		print_status(phi->num_philo, phi->table, "died");
		return (0);
	}
	if (phi->table->philo_dead)
		return (0);
	if (phi->times_eaten >= table->num_must_eat && table->num_must_eat != -1)
		return (0);
	return (1);
}

int	time_math(struct timeval time_behind, struct timeval time_ahead)
{
	return ((int)(((time_ahead.tv_sec - time_behind.tv_sec) * 1000
			+ (time_ahead.tv_usec - time_behind.tv_usec) / 1000)));
}

int	setup_table(t_data *table, int ac, char **av)
{
	setup_table_specs(table, ac, av);
	if (table->num_philos <= 0 || table->tt_die <= 0
		|| table->tt_eat <= 0 || table->tt_sleep <= 0)
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
	else if (ac == 6 && ft_atoi(av[5]) < 0)
		return (0);
	else
		table->num_must_eat = -1;
	pthread_mutex_init(&table->mprint, NULL);
	return (1);
}
