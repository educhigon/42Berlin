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
	int ret;

	ret = 1;
	gettimeofday(&now, NULL);
	pthread_mutex_lock(&table->philo_dead_mutex);
	pthread_mutex_lock(&phi->times_eaten_mutex);
	pthread_mutex_lock(&phi->time_last_eaten_mutex);

	if (time_math(phi->time_last_eaten, now) > phi->table->tt_die
		&& phi->table->philo_dead != 1)
	{
		// print_status(phi->num_philo, phi->table, "died");
		phi->table->philo_dead = 1;
		ret = 0;
	}
	if (phi->table->philo_dead)
		ret = 0;
    // printf("DEBUG: Philo %d has eaten %d times\n", phi->num_philo, phi->times_eaten);

	if (phi->times_eaten >= table->num_must_eat && table->num_must_eat != -1)
		ret = 0;

	pthread_mutex_unlock(&phi->time_last_eaten_mutex);
	pthread_mutex_unlock(&phi->times_eaten_mutex);
	pthread_mutex_unlock(&table->philo_dead_mutex);
	return(ret);
}

int	time_math(struct timeval time_behind, struct timeval time_ahead)
{
	int i;

	i = (int)(((time_ahead.tv_sec - time_behind.tv_sec) * 1000
			+ (time_ahead.tv_usec - time_behind.tv_usec) / 1000));
	if (i)
		return (i);
	return (1);
	// return ((int)(((time_ahead.tv_sec - time_behind.tv_sec) * 1000
	// 		+ (time_ahead.tv_usec - time_behind.tv_usec) / 1000)));
}

int	setup_table(t_data *table, int ac, char **av)
{
	pthread_mutex_init(&table->philo_dead_mutex, NULL);
	pthread_mutex_init(&table->mprint, NULL);

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
	return (1);
}
