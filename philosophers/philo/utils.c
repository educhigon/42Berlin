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
		write(1, " (optional)<Number of times each philosopher must eat>\n", 55);
		return (0);
	}
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[2]) == 0
		|| ft_atoi(av[3]) == 0 || ft_atoi(av[4]) == 0)
	{
		write(1, "# of Philosophers or any of their times cannot be 0\n", 61);
		return (0);
	}
	return (1);
}

int	time_math(struct timeval time_behind, struct timeval time_ahead)
{
	return ((time_ahead.tv_sec - time_behind.tv_sec) * 1000
		+ (time_ahead.tv_usec - time_behind.tv_usec) / 1000);
}

int	iam_alive(t_philo *phi, t_data *table)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_math(phi->time_last_eaten, tv) > table->tt_die)
	{
		philo_dead(phi, table);
		return (0);
	}
	if (phi->times_eaten >= table->num_must_eat)
		return (0);
	return (1);
}

void	print_status(int philo_num, t_data *table, int event)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (event == 0)
		printf("[%d] - [%d] has taken a fork\n",
			time_math(table->dinner_start, tv), philo_num);
	else if (event == 1)
		printf("[%d] - [%d] is eating\n",
			time_math(table->dinner_start, tv), philo_num);
	else if (event == 2)
		printf("[%d] - [%d] is sleeping\n",
			time_math(table->dinner_start, tv), philo_num);
	else if (event == 3)
		printf("[%d] - [%d] is thinking\n",
			time_math(table->dinner_start, tv), philo_num);
	else if (event == 4)
		printf("[%d] - [%d] died\n",
			time_math(table->dinner_start, tv), philo_num);
	return ;
}

void	free_data(t_data *table)
{
	int	i;

	if (table->philos != NULL)
		free(table->philos);
	if (table->forks != NULL)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->mprint);
	return ;
}
