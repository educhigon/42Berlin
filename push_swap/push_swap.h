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
void		print_array(int **arrays, int *sizes);
int			i_ate(int size, int index);
void		create_helper_num(int *arr, int size);

//Libft + ft_printf
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int			ft_printf(const char *str, ...);

// Start Sorting
int			sort(int **arrays, int *sizes);

// Sorting Utils
int			count_movements(int *sizes, int i_a, int i_b);
void		fill_helper_num(int *sizes, int *hn);
int			mutual_rotations(int **arrays, int *sizes, int *hn);
void		unique_rotations(int **arrays, int *sizes, int *hn);

void		filling_b(int **arrays, int *sizes);
void		refilling_a(int **arrays, int *sizes);

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