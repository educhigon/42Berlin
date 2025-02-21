/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:09:59 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/05 17:27:51 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int i;

	i = 0;
	write(1, "\n A  B\n[", 8);
	ft_putnbr_fd(size_a, 1);
	write(1, "][", 2);
	ft_putnbr_fd(size_b, 1);
	write(1, "]\n------\n", 9);
	while (i < size_a || i < size_b)
	{
		write(1, " ", 1);
		if (i < size_a)
			ft_putnbr_fd(arr_a[i], 1);
		write(1, "  ", 2);
		if (i < size_b)
			ft_putnbr_fd(arr_b[i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 2);
	return;
}

int is_a_sorted(int **arr_a, int size_a)
{
	int i;
	int j;
	// write(1,"\nsize_b: ",10);
	// ft_putnbr_fd(size_b, 1);
	// write(1,"\nsize_a: ",10);
	// ft_putnbr_fd(size_a, 1);

	// if (size_b != 0)
	// 	return (0);
	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			// write(1,"\narr_a[i]: ",11);
			// ft_putnbr_fd((*arr_a)[i], 1);
			// write(1,"\narr_a[j]: ",11);
			// ft_putnbr_fd((*arr_a)[j], 1);
		
			if ((*arr_a)[i] > (*arr_a)[j])
				return (0);
			j++;
		}
		i++;
	}
	// write(1,"\nI want to answer yes!\n", 23);
	return (1);
}

int	sort(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int i = 0;
	// print_array(*arr_a,*arr_b, *size_a, *size_b);
	while((!is_a_sorted(arr_a, *size_a) || *size_b != 0) && i !=5)
	{
		
		if(*size_a == 3 && !is_a_sorted(arr_a, *size_a))
			sort_a_3(arr_a, arr_b, size_a, size_b);
		
		if(*size_b == 0 && !is_a_sorted(arr_a, *size_a))
		{
			pb(arr_a, arr_b, size_a, size_b);
			if (*size_a == 3)
				continue;
			pb(arr_a, arr_b, size_a, size_b);
			continue;
		}
		
		if(!is_a_sorted(arr_a, *size_a))
			filling_b(arr_a, arr_b, size_a, size_b);
			
		// write(1,"\nis_a_sorted?: ",15);
		// ft_putnbr_fd(is_a_sorted(arr_a, *size_a, *size_b), 1);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		
		// write(1,"\n",1);
		if(is_a_sorted(arr_a, *size_a) && *size_b != 0)
			refilling_a(arr_a, arr_b, size_a, size_b);
		i++;	
	}
	// write(1,"\nhere1\n",7);
	return (1);
}

void	set_arr(int ac, char *av[])
{
	int	i;
	int *arr_a;
	int *arr_b;
	int size_a;
	int size_b;
	
	arr_a = malloc((ac) * sizeof(int));
	arr_b = malloc((ac) * sizeof(int));
	if (arr_a == NULL || arr_b == NULL) {
		write(2, "Error: Uninitialized array\n", 27);
		return;
	}
	size_a = ac;
	size_b = 0;
	i = 0;
	while (i < ac)
	{
		arr_a[i] = ft_atoi_here(av[i + 1]);
		i++;
	}
	sort(&arr_a, &arr_b, &size_a, &size_b);
	print_array(arr_a,arr_b, size_a, size_b);
	free(arr_a);
	free(arr_b);
	// write(1,"\nhere\n\n",7);
	return;
}

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		return (write(2, "Error\n", 6));
	while (av[i] != NULL)
	{
		// write(1, "Testing INT\n", 12);
		if (!check_int(av[i]))
			return (write(2, "Error\n", 6));
		// write(1, "Testing BIG INT\n", 16);
		if (!check_big_int(av[i]))
			return (write(2, "Error\n", 6));
		j = i + 1;
		while (av[j] != NULL)
		{
			// printf("av[i=%d]: %s & av[j=%d]: %s\n",i, av[i], j, av[j]);
			if (ft_atoi_here(av[j]) == ft_atoi_here(av[i]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	set_arr(ac - 1, av);
	// write(1,"\n\nhere\n",7);

	return (1);
}



		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// sa(arr_a, arr_b, size_a, size_b);
		// write(1,"--> SA\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// ra(arr_a, arr_b, size_a, size_b);
		// write(1,"--> RA\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// pb(arr_a, arr_b, size_a, size_b);
		// write(1,"--> PB\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// pb(arr_a, arr_b, size_a, size_b);
		// write(1,"--> PB\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// pa(arr_a, arr_b, size_a, size_b);
		// write(1,"--> PA\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// rra(arr_a, arr_b, size_a, size_b);
		// write(1,"--> RRA\n",8);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// pb(arr_a, arr_b, size_a, size_b);
		// write(1,"--> PA\n",7);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		// rrr(arr_a, arr_b, size_a, size_b);
		// write(1,"--> RRR\n",8);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
