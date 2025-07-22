/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 09:57:55 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-29 09:57:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	final_nbr;
	int	power;

	final_nbr = 0;
	i = 0;
	power = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			power *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		final_nbr = final_nbr * 10 + (str[i] - '0') * power;
		i++;
	}
	return (final_nbr);
}

int	check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		write(1, "Usage: <./philo> <Number of Philosophers> <Time to die>", 55);
		write(1, " <Time to eat> <Time to sleep>", 30);
		write(1, " (optional)<Number of times each philo must eat>\n", 49);
		return (0);
	}
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[2]) == 0
		|| ft_atoi(av[3]) == 0 || ft_atoi(av[4]) == 0)
	{
		write(1, "# of Philosophers or any of their times cannot be 0\n", 53);
		return (0);
	}
	return (1);
}

void	setup_table_specs(t_data *table, int ac, char **av)
{
	table->num_philos = ft_atoi(av[1]);
	table->tt_die = ft_atoi(av[2]);
	table->tt_eat = ft_atoi(av[3]);
	table->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->num_must_eat = ft_atoi(av[5]);
	table->philos = NULL;
	table->forks = NULL;
	pthread_mutex_lock(&table->philo_dead_mutex);
	table->philo_dead = 0;
	pthread_mutex_unlock(&table->philo_dead_mutex);
	return ;
}

int	free_data(t_data *table)
{
	int	i;
	usleep(1000);
	if (table->philos != NULL)
		free(table->philos);
	if (table->forks != NULL)
	{
		i = -1;
		while (++i < table->num_philos)
		{
			// pthread_mutex_unlock(&table->forks[i]);
			pthread_mutex_destroy(&table->philos[i].times_eaten_mutex);
			pthread_mutex_destroy(&table->philos[i].time_last_eaten_mutex);
			pthread_mutex_destroy(&table->forks[i]);
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->mprint);
	pthread_mutex_destroy(&table->philo_dead_mutex);
	return (1);
}
