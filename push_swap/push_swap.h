/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:22 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/05 17:10:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

int	push_swap(int ac, char *av[]);
int	ft_strlen(char *str);
long long	ft_atoi_here(const char *str);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
int	check_big_int(char *str);
int	check_int(char *str);
void	ft_putnbr_fd(int n, int fd);

void	print_array(int *arr_a, int *arr_b, int size_a, int size_b);

void	sa(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	sb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	ss(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	pa(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	pb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	ra(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	rb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	rr(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	rra(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	rrb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void	rrr(int **arr_a, int **arr_b, int *size_a, int *size_b);

void sort_a_3(int **arr_a, int **arr_b, int *size_a, int *size_b);
void filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b);
void refilling_a(int **arr_a, int **arr_b, int *size_a, int *size_b);
int	i_ATE(int size, int index);




#endif