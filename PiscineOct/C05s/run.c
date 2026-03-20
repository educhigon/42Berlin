/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:05 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 10:12:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


const int START = 0;
const int NUM_EXEC = 7;

#include "C05-try0/ex00/ft_iterative_factorial.c"
#include "C05-try0/ex01/ft_recursive_factorial.c"
#include "C05-try0/ex02/ft_iterative_power.c"
#include "C05-try0/ex03/ft_recursive_power.c"
#include "C05-try0/ex04/ft_fibonacci.c"
#include "C05-try0/ex05/ft_sqrt.c"
#include "C05-try0/ex06/ft_is_prime.c"
#include "C05-try0/ex07/ft_find_next_prime.c"

void ex07()
{
	printf("Find next prime of nbr -1 : '%d'\n", ft_find_next_prime(-1));
	printf("Find next prime of nbr 0 : '%d'\n", ft_find_next_prime(0));
	printf("Find next prime of nbr 1 : '%d'\n", ft_find_next_prime(1));
	printf("Find next prime of nbr 2 : '%d'\n", ft_find_next_prime(2));
	printf("Find next prime of nbr 3 : '%d'\n", ft_find_next_prime(3));
	printf("Find next prime of nbr 4 : '%d'\n", ft_find_next_prime(4));
	printf("Find next prime of nbr 5 : '%d'\n", ft_find_next_prime(5));
	printf("Find next prime of nbr 6 : '%d'\n", ft_find_next_prime(6));
	printf("Find next prime of nbr 7 : '%d'\n", ft_find_next_prime(7));
	printf("Find next prime of nbr 8 : '%d'\n", ft_find_next_prime(8));
	printf("Find next prime of nbr 9 : '%d'\n", ft_find_next_prime(9));
	printf("Find next prime of nbr 10 : '%d'\n", ft_find_next_prime(10));
	printf("Find next prime of nbr 11 : '%d'\n", ft_find_next_prime(11));
	printf("Find next prime of nbr 12 : '%d'\n", ft_find_next_prime(12));
}

void ex06()
{
	printf("Check if nbr -1 is prime: '%d'\n", ft_is_prime(-1));
	printf("Check if nbr 0 is prime: '%d'\n", ft_is_prime(0));
	printf("Check if nbr 1 is prime: '%d'\n", ft_is_prime(1));
	printf("Check if nbr 2 is prime: '%d'\n", ft_is_prime(2));
	printf("Check if nbr 3 is prime: '%d'\n", ft_is_prime(3));
	printf("Check if nbr 4 is prime: '%d'\n", ft_is_prime(4));
	printf("Check if nbr 5 is prime: '%d'\n", ft_is_prime(5));
	printf("Check if nbr 6 is prime: '%d'\n", ft_is_prime(6));
	printf("Check if nbr 7 is prime: '%d'\n", ft_is_prime(7));
	printf("Check if nbr 8 is prime: '%d'\n", ft_is_prime(8));
	printf("Check if nbr 9 is prime: '%d'\n", ft_is_prime(9));
	printf("Check if nbr 10 is prime: '%d'\n", ft_is_prime(10));
	printf("Check if nbr 11 is prime: '%d'\n", ft_is_prime(11));
	printf("Check if nbr 12 is prime: '%d'\n", ft_is_prime(12));
}

void ex05()
{
	printf("SQRT nbr -1 is: '%d'\n", ft_sqrt(-1));
	printf("SQRT nbr 0 is: '%d'\n", ft_sqrt(0));
	printf("SQRT nbr 1 is: '%d'\n", ft_sqrt(1));
	printf("SQRT nbr 2 is: '%d'\n", ft_sqrt(2));
	printf("SQRT nbr 3 is: '%d'\n", ft_sqrt(3));
	printf("SQRT nbr 4 is: '%d'\n", ft_sqrt(4));
	printf("SQRT nbr 5 is: '%d'\n", ft_sqrt(5));
	printf("SQRT nbr 6 is: '%d'\n", ft_sqrt(6));
	printf("SQRT nbr 7 is: '%d'\n", ft_sqrt(7));
	printf("SQRT nbr 8 is: '%d'\n", ft_sqrt(8));
	printf("SQRT nbr 9 is: '%d'\n", ft_sqrt(9));
	printf("SQRT nbr 16 is: '%d'\n", ft_sqrt(16));
	printf("SQRT nbr 25 is: '%d'\n", ft_sqrt(25));
	printf("SQRT nbr 36 is: '%d'\n", ft_sqrt(36));
}

void ex04()
{
	printf("Fibonacci nbr -1 is: '%d'\n", ft_fibonacci(-1));
	printf("Fibonacci nbr 0 is: '%d'\n", ft_fibonacci(0));
	printf("Fibonacci nbr 1 is: '%d'\n", ft_fibonacci(1));
	printf("Fibonacci nbr 2 is: '%d'\n", ft_fibonacci(2));
	printf("Fibonacci nbr 3 is: '%d'\n", ft_fibonacci(3));
	printf("Fibonacci nbr 4 is: '%d'\n", ft_fibonacci(4));
	printf("Fibonacci nbr 5 is: '%d'\n", ft_fibonacci(5));
	printf("Fibonacci nbr 6 is: '%d'\n", ft_fibonacci(6));
	printf("Fibonacci nbr 7 is: '%d'\n", ft_fibonacci(7));
	printf("Fibonacci nbr 8 is: '%d'\n", ft_fibonacci(8));

}
void ex03()
{
	printf("power of 2 to 6 is: '%d'\n", ft_iterative_power(2, 6));
	printf("power of 2 to 5 is: '%d'\n", ft_iterative_power(2, 5));
	printf("power of 2 to 4 is: '%d'\n", ft_iterative_power(2, 4));
	printf("power of 2 to 3 is: '%d'\n", ft_iterative_power(2, 3));
	printf("power of 2 to 2 is: '%d'\n", ft_iterative_power(2, 2));
	printf("power of 2 to 1 is: '%d'\n", ft_iterative_power(2, 1));
	printf("power of 2 to 0 is: '%d'\n", ft_iterative_power(2, 0));
	printf("power of -2 to 0 is: '%d'\n", ft_iterative_power(2, 0));
	printf("power of -2 to 1 is: '%d'\n", ft_iterative_power(-2, 1));
	printf("power of -2 to 2 is: '%d'\n", ft_iterative_power(-2, 2));
	printf("power of -2 to 3 is: '%d'\n", ft_iterative_power(-2, 3));
	printf("power of -2 to 4 is: '%d'\n", ft_iterative_power(-2, 4));
	printf("power of -2 to 5 is: '%d'\n", ft_iterative_power(-2, 5));
	printf("power of -2 to 6 is: '%d'\n", ft_iterative_power(-2, 6));

}
void ex02()
{
	printf("power of 2 to 0 is: '%d'\n", ft_iterative_power(2, 0));
	printf("power of 2 to 1 is: '%d'\n", ft_iterative_power(2, 1));
	printf("power of 2 to 2 is: '%d'\n", ft_iterative_power(2, 2));
	printf("power of 2 to 6 is: '%d'\n", ft_iterative_power(2, 6));
	printf("power of -2 to 0 is: '%d'\n", ft_iterative_power(-2, 0));
	printf("power of -2 to 4 is: '%d'\n", ft_iterative_power(-2, 4));
	printf("power of -2 to 5 is: '%d'\n", ft_iterative_power(-2, 5));
	printf("power of -2 to 6 is: '%d'\n", ft_iterative_power(-2, 6));

}
void ex01()
{
	printf("factorial of 13 is: '%d'\n", ft_recursive_factorial(13));
	printf("factorial of 12 is: '%d'\n", ft_recursive_factorial(12));
	printf("factorial of 11 is: '%d'\n", ft_recursive_factorial(11));
	printf("factorial of 10 is: '%d'\n", ft_recursive_factorial(10));
	printf("factorial of 9 is: '%d'\n", ft_recursive_factorial(9));
	printf("factorial of 8 is: '%d'\n", ft_recursive_factorial(8));
	printf("factorial of 7 is: '%d'\n", ft_recursive_factorial(7));
	printf("factorial of 6 is: '%d'\n", ft_recursive_factorial(6));
	printf("factorial of 5 is: '%d'\n", ft_recursive_factorial(5));
	printf("factorial of 4 is: '%d'\n", ft_recursive_factorial(4));
	printf("factorial of 3 is: '%d'\n", ft_recursive_factorial(3));
	printf("factorial of 2 is: '%d'\n", ft_recursive_factorial(2));
	printf("factorial of 1 is: '%d'\n", ft_recursive_factorial(1));
	printf("factorial of 0 is: '%d'\n", ft_recursive_factorial(0));
	printf("factorial of -1 is: '%d'\n", ft_recursive_factorial(-1));
	printf("factorial of -2 is: '%d'\n", ft_recursive_factorial(-2));
	printf("factorial of -3 is: '%d'\n", ft_recursive_factorial(-3));
	printf("factorial of -4 is: '%d'\n", ft_recursive_factorial(-4));
	printf("factorial of -5 is: '%d'\n", ft_recursive_factorial(-5));
	printf("factorial of -6 is: '%d'\n", ft_recursive_factorial(-6));
	printf("factorial of -7 is: '%d'\n", ft_recursive_factorial(-7));
}

void ex00()
{
	printf("factorial of 13 is: '%d'\n", ft_iterative_factorial(13));
	printf("factorial of 12 is: '%d'\n", ft_iterative_factorial(12));
	printf("factorial of 11 is: '%d'\n", ft_iterative_factorial(11));
	printf("factorial of 10 is: '%d'\n", ft_iterative_factorial(10));
	printf("factorial of 9 is: '%d'\n", ft_iterative_factorial(9));
	printf("factorial of 8 is: '%d'\n", ft_iterative_factorial(8));
	printf("factorial of 7 is: '%d'\n", ft_iterative_factorial(7));
	printf("factorial of 6 is: '%d'\n", ft_iterative_factorial(6));
	printf("factorial of 5 is: '%d'\n", ft_iterative_factorial(5));
	printf("factorial of 4 is: '%d'\n", ft_iterative_factorial(4));
	printf("factorial of 3 is: '%d'\n", ft_iterative_factorial(3));
	printf("factorial of 2 is: '%d'\n", ft_iterative_factorial(2));
	printf("factorial of 1 is: '%d'\n", ft_iterative_factorial(1));
	printf("factorial of 0 is: '%d'\n", ft_iterative_factorial(0));
	printf("factorial of -1 is: '%d'\n", ft_iterative_factorial(-1));
	printf("factorial of -2 is: '%d'\n", ft_iterative_factorial(-2));
	printf("factorial of -3 is: '%d'\n", ft_iterative_factorial(-3));
	printf("factorial of -4 is: '%d'\n", ft_iterative_factorial(-4));
	printf("factorial of -5 is: '%d'\n", ft_iterative_factorial(-5));
	printf("factorial of -6 is: '%d'\n", ft_iterative_factorial(-6));
	printf("factorial of -7 is: '%d'\n", ft_iterative_factorial(-7));
}

void find_ex(int i)
{
	switch (i)
	{
	case 0:
		ex00();
		break;
	case 1:
		ex01();
		break;
	case 2:
		ex02();
		break;
	case 3:
		ex03();
		break;
	case 4:
		ex04();
		break;
	case 5:
		ex05();
		break;
	case 6:
		ex06();
		break;
	case 7:
		ex07();
		break;
	default:
		break;
	}
}

int main()
{
	int i = START;

	while(i <= NUM_EXEC)
	{
		printf("\n\n#-------TESTING EX%d  ----------------: \n", i);
		find_ex(i);
		i++;
	}
}