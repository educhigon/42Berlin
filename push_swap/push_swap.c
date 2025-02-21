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

void	slide_arr(int **arr_a, int **arr_b, int *size_a, int *size_b, int i_biggest)
{
	// write(1,"\ni_biggest: ",12);
	// ft_putnbr_fd(i_biggest, 1);
	// write(1,"\n",1);
	// write(1,"\nsize_a: ",9);
	// ft_putnbr_fd(*size_a, 1);
	// write(1,"\n",1);

	if (i_ATE(*size_a, i_biggest))
	{
		while (i_biggest < *size_a - 1)
		{
			rra(arr_a, arr_b, size_a, size_b);
			i_biggest++;
		}
	}
	else
	{
		while (i_biggest >= 0)
		{
			ra(arr_a, arr_b, size_a, size_b);
			i_biggest--;
		}
	}
	return;
	
}
void	if_sorted_slide_than_sort(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i;
	int	i_biggest;

	i = 0;
	i_biggest = 0;
	if (*size_b != 0)
		return;
	if (*size_a == 2 && (*arr_a)[0] > (*arr_a)[1])
	{
		ra(arr_a, arr_b, size_a, size_b);
		return;
	}
	
	while (i < *size_a)
	{
		if ((*arr_a)[i_biggest] < (*arr_a)[i])
			i_biggest = i;
		i++;
	}
	i = 0;
	// write(1,"\ni_biggest: ",12);
	// ft_putnbr_fd(i_biggest, 1);
	// write(1,"\n",1);
	
	while (i + 1 < *size_a)
	{
		// write(1,"\n-->i: ",7);
		// ft_putnbr_fd(i, 1);
		// write(1,"\n",1);
		if ((*arr_a)[i] > (*arr_a)[i + 1] && i != i_biggest)
			return;
		i++;
	}
	// write(1,"\ni_biggest: ",12);
	// ft_putnbr_fd(i_biggest, 1);
	// write(1,"\n",1);
	// print_array(*arr_a,*arr_b, *size_a, *size_b);
	
	// write(1,"let's slide\n",12);
	slide_arr(arr_a,arr_b, size_a, size_b, i_biggest);
	// print_array(*arr_a,*arr_b, *size_a, *size_b);
}

int is_a_sorted(int *arr_a, int size_a)
{
	int i;
	int j;
	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (arr_a[i] > arr_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sort(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int i = 0;
	// int limit = 0;
	// print_array(*arr_a,*arr_b, *size_a, *size_b);
	// if_sorted_slide_than_sort(arr_a, arr_b, size_a, size_b);

	while((!is_a_sorted(*arr_a, *size_a)) || *size_b != 0)
	{
		if_sorted_slide_than_sort(arr_a, arr_b, size_a, size_b);

		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		
		if(*size_a == 3 && !is_a_sorted(*arr_a, *size_a))
			sort_a_3(arr_a, arr_b, size_a, size_b);
		
		if(*size_b == 0 && !is_a_sorted(*arr_a, *size_a))
		{
			pb(arr_a, arr_b, size_a, size_b);
			if (*size_a == 3)
				continue;
			pb(arr_a, arr_b, size_a, size_b);
			continue;
		}
		
		if(!is_a_sorted(*arr_a, *size_a))
		filling_b(arr_a, arr_b, size_a, size_b);
		if(is_a_sorted(*arr_a, *size_a) && *size_b != 0)
		refilling_a(arr_a, arr_b, size_a, size_b);
		// if_sorted_slide_than_sort(arr_a, arr_b, size_a, size_b);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);
		i++;
		// limit++;
	}
	// print_array(*arr_a,*arr_b, *size_a, *size_b);

	// write(1,"\nhere1\n",7);
	return (1);
}

void	set_arr(int ac, char **av)
{
	int	i;
	int *arr_a;
	int *arr_b;
	int size_a;
	int size_b;
	
	arr_a = malloc((ac) * sizeof(int));
	arr_b = malloc((ac) * sizeof(int));
	if (arr_a == NULL || arr_b == NULL) {
		return;
	}
	size_a = ac;
	size_b = 0;
	i = 0;
	while (i < ac)
	{
		// write(1,"\nav[i]: ",8);
		// write(1,av[i], ft_strlen(av[i]));
		// write(1,"\n",1);

		arr_a[i] = ft_atoi_here(av[i]);
		i++;
	}
	sort(&arr_a, &arr_b, &size_a, &size_b);
	// print_array(arr_a,arr_b, size_a, size_b);
	free(arr_a);
	free(arr_b);
	// write(1,"\nhere\n\n",7);
	return;
}

int	verify_input(int ac, char **input, int i)
{
	int	j;
	
	while (i < ac)
	{
		// write(1,"\nav[i]: ",8);
		// write(1,input[i], ft_strlen(input[i]));
		// write(1,"\n",1);
	
		// write(1, "Testing INT\n", 12);
		if (!check_int(input[i]))
			return (write(2, "Error\n", 6));
		// write(1, "Testing BIG INT\n", 16);
		if (!check_big_int(input[i]))
			return (write(2, "Error\n", 6));
		j = i + 1;
		while (j < ac)
		{
			// printf("av[i=%d]: %s & av[j=%d]: %s\n",i, input[i], j, input[j]);
			if (ft_atoi_here(input[j]) == ft_atoi_here(input[i]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	char **input;
	// write(1,"\nac: ",5);
	// ft_putnbr_fd(ac, 1);
	// write(1,"\n",1);
	// write(1,"\nav[0]: ",8);
	// write(1,av[0], ft_strlen(av[0]));
	// write(1,"\n",1);
	// write(1,"\nav[1]: ",8);
	// write(1,av[1], ft_strlen(av[1]));
	// write(1,"\n",1);

	if (ac == 2)
	{
		if ((*av)[1] == '\0')
			return (write(2, "Error\n", 6));
		ac = 0;
		input = ft_split(av[1], ' ');
		while (input[ac] != NULL)
			ac++;
		if(verify_input(ac, input, 0) == 6)
		{
			free(input);
			return(0);
		}
		set_arr(ac, input);
		free(input);
	}
	else
	{
		if(verify_input(ac, av, 1) == 6)
			return(0);
		set_arr(ac - 1, &av[1]);
	}
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
