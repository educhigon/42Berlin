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


#ifndef WIREFRAME_H
# define WIREFRAME_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int		num_philo;
	long	tt_die;
	long	tt_eat;
	long	tt_sleep;
	int		num_must_eat;
	
}	t_philo;

// Philo
int	main(int ac, char *av)

// Utils
int	ft_atoi(const char *str);


#endif