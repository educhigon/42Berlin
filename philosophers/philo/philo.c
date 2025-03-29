/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 09:30:32 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-29 09:30:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*thread_func(void *arg) {
	printf("Thread running with arg: %d\n", *(int *)arg);
	return NULL;
}

void	create_philos(t_philo philo, int i, char *av)
{
	pthread_t t1;

	philos.num_philo = i;
	philos.tt_die = ft_atoi(av[2]);
	philos.tt_eat = ft_atoi(av[3]);
	philos.tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philos.num_must_eat = av[5];
	pthread_create(&thread, NULL, thread_func, &arg);
}

int	main(int ac, char *av)
{
	t_philo *philos;
	pthread_t thread;

	if (ac < 5 || ac > 6)
	{
		write("Usage: <./philo> <Number of Philosophers> <Time to die>");
		write(" <Time to eat> <Time to sleep>");
		write(" (optional)<Number of times each philosopher must eat>");
		return (0);
	}
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[2]) == 0 || ft_atoi(av[3]) == 0 || ft_atoi(av[4]) == 0)
	{
		write("The number of Philosophers or any of their times cannot be 0");
		return (0);
	}
	philos = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	int i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		create_philos(philos[i], i, av);
		i++;
	}

	
	
}