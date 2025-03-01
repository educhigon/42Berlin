/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 19:38:42 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-25 19:38:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include "libft.h"

//Main
int			main(int ac, char *av[]);

//Verification
int			verify_input(int ac, char **input, int i);
void		free_mem(char **input, int ac);
int			is_a_sorted(int *arr_a, int size_a);

// Check Sorter
int			check_s(int **arrays, int *sizes);
int			check_p(int **arrays, int *sizes);
int			check_r(int **arrays, int *sizes);

// Utils
long long	ft_atoi_here(const char *str);
void		print_array(int **arrays, int *sizes);

// Functions
void		sa(int **arrays, int *sizes);
void		sb(int **arrays, int *sizes);
void		ss(int **arrays, int *sizes);
void		pa(int **arrays, int *sizes);
void		pb(int **arrays, int *sizes);
void		ra(int **arrays, int *sizes);
void		rb(int **arrays, int *sizes);
void		rr(int **arrays, int *sizes);
void		rra(int **arrays, int *sizes);
void		rrb(int **arrays, int *sizes);
void		rrr(int **arrays, int *sizes);

#endif