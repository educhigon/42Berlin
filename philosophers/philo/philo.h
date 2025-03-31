/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 09:12:26 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-29 09:12:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				num_philo;
	pthread_t		philo_thread;
	struct timeval	time_last_eaten;
	int				times_eaten;
	t_data			*table;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mprint;
	t_philo			*philos;
	struct timeval	dinner_start;
	int				num_philos;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_must_eat;
}	t_data;

// Philo
int		main(int ac, char **av);

// Utils
int		ft_atoi(char *str);
int		check_input(int ac, char **av);
int		check_philos_alive(t_philo *philos, int num_philos);
int		iam_alive(t_philo *phi, t_data *table);
void	print_status(int philo_num, t_data *table, int event);
void	free_data(t_data *table);

// Functions
void	philo_take_fork(t_philo *phi, t_data *table);
void	philo_eating(t_philo *phi, t_data *table);
void	philo_sleeping(t_philo *phi, t_data *table);
void	philo_thinking(t_philo *phi, t_data *table);
void	philo_dead(t_philo *phi, t_data *table);

#endif