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

//Main
int			main(int ac, char *av[]);

//Verification
int			verify_input(int ac, char **input, int i);

// Utils
long long	ft_atoi_here(const char *str);
void		ft_putnbr_fd(int n, int fd);
void		print_array(int *arr_a, int *arr_b, int size_a, int size_b);
int			i_ate(int size, int index);
void		create_helper_num(int *arr, int size);

//Libft + ft_printf
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int			ft_printf(const char *str, ...);

// Start Sorting
int			sort(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		refilling_a(int **arr_a, int **arr_b, int *size_a, int *size_b);

// Functions
void		sa(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		sb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		ss(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		pa(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		pb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		ra(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		rb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		rr(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		rra(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		rrb(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		rrr(int **arr_a, int **arr_b, int *size_a, int *size_b);

#endif