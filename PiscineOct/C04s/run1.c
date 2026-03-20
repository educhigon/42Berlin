/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:58:43 by lgruner           #+#    #+#             */
/*   Updated: 2024/10/23 17:54:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "C04/ex00/ft_strlen.c"
#include "C04/ex01/ft_putstr.c"
#include "C04/ex02/ft_putnbr.c"
#include "C04/ex03/ft_atoi.c"
// #include "C04/ex04/ft_putnbr_base.c"
#include "C04/ex05/ft_atoi_base.c"

void	ex00(void)
{
	char str1[] = "Hello world";
	char str2[] = "0123456789";
	char str3[] = "qwertyuiop<>??";
	char str4[] = "";

	printf("'%s'\nstrlen: %lu, ft_strlen: %d\n\n", str1, strlen(str1), ft_strlen(str1));
	printf("'%s'\nstrlen: %lu, ft_strlen: %d\n\n", str2, strlen(str2), ft_strlen(str2));
	printf("'%s'\nstrlen: %lu, ft_strlen: %d\n\n", str3, strlen(str3), ft_strlen(str3));
	printf("'%s'\nstrlen: %lu, ft_strlen: %d\n\n", str4, strlen(str4), ft_strlen(str4));
}

void	ex01(void)
{
	char str1[] = "Hello world";
	char str2[] = "0123456789";
	char str3[] = "qwertyuiop<>??";
	char str4[] = "";

	ft_putstr(str1);
	write(1, "\n", 1);
	ft_putstr(str2);
	write(1, "\n", 1);
	ft_putstr(str3);
	write(1, "\n", 1);
	ft_putstr(str4);
	write(1, "\n", 1);
}

void	ex02(void)
{
	int nb1 = 2147483647;
	int nb2 = 123456789;
	int nb3 = 123;
	int nb4 = 0;
	int nb5 = -123;
	int nb6 = -123465789;
	int nb7 = -2147483648;

	ft_putnbr(nb1);
	write(1, "\n", 1);
	ft_putnbr(nb2);
	write(1, "\n", 1);
	ft_putnbr(nb3);
	write(1, "\n", 1);
	ft_putnbr(nb4);
	write(1, "\n", 1);
	ft_putnbr(nb5);
	write(1, "\n", 1);
	ft_putnbr(nb6);
	write(1, "\n", 1);
	ft_putnbr(nb7);
	write(1, "\n", 1);
}

void	ex03(void)
{
	char str1[] = "123";
	char str2[] = "-123";
	char str3[] = "0";
	char str4[] = "123abc";
	char str5[] = "	  123";
	char str6[] = "--+--+-+-+--123";
	char str7[] =  " ---+--+1234ab567";
	char str8[] = "-2147483648";
	char str9[] = "\n\t\v  ++++++++++-+999XCV";
	char str10[] = " \t\nB+++++123";

	printf("'%s': %d\n", str1, ft_atoi(str1));
	printf("'%s': %d\n", str2, ft_atoi(str2));
	printf("'%s': %d\n", str3, ft_atoi(str3));
	printf("'%s': %d\n", str4, ft_atoi(str4));
	printf("'%s': %d\n", str5, ft_atoi(str5));
	printf("'%s': %d\n", str6, ft_atoi(str6));
	printf("'%s': %d\n", str7, ft_atoi(str7));
	printf("'%s': %d\n", str8, ft_atoi(str8));
	printf("'%s': %d\n", str9, ft_atoi(str9));
	printf("'%s': %d\n", str10, ft_atoi(str10));
}


void	ex04(void)
{
	int nbr1 = 123456789;
	int nbr2 = -2147483648;
	int nbr3 = 0;
	
	char decimal[] = "0123456789";
	char binary[] = "01";
	char hex[] = "0123456789ABCDEF";
	char octal[] = "01234567";
	char poney[] = "poneyvif";

	write(1, "123456789", 9);
	write(1, "\n", 1);
	ft_putnbr_base(nbr1, decimal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr1, binary);
	write(1, "\n", 1);
	ft_putnbr_base(nbr1, hex);
	write(1, "\n", 1);
	ft_putnbr_base(nbr1, octal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr1, poney);
	write(1, "\n", 1);
	write(1, "\n", 1);

	write(1, "-2147483648", 11);
	write(1, "\n", 1);
	ft_putnbr_base(nbr2, decimal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr2, binary);
	write(1, "\n", 1);
	ft_putnbr_base(nbr2, hex);
	write(1, "\n", 1);
	ft_putnbr_base(nbr2, octal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr2, poney);
	write(1, "\n", 1);
	write(1, "\n", 1);

	write(1, "0", 1);
	write(1, "\n", 1);
	ft_putnbr_base(nbr3, decimal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr3, binary);
	write(1, "\n", 1);
	ft_putnbr_base(nbr3, hex);
	write(1, "\n", 1);
	ft_putnbr_base(nbr3, octal);
	write(1, "\n", 1);
	ft_putnbr_base(nbr3, poney);
	write(1, "\n", 1);
	write(1, "\n", 1);

	write(1, "Invalid bases\n", 14);
	write(1, "01234456799\n", 12);
	ft_putnbr_base(nbr1, "01234456799");
	write(1, "''\n", 3);
	ft_putnbr_base(nbr1, "");
	write(1, "1\n", 2);
	ft_putnbr_base(nbr1, "1");
	write(1, "+poney\n", 7);
	ft_putnbr_base(nbr1, "+poney");
	write(1, "-3\n", 3);
	ft_putnbr_base(nbr1, "-3");
	write(1, "\n", 1);
}

void	ex05()
{
	char decimal[] = "0123456789";
	char binary[] = "01";
	char hex[] = "0123456789ABCDEF";
	//char octal[] = "01234567";
	//char poney[] = "poneyvif";

	printf("decimal: '%s'\n", decimal);
	char nb1[] = " ---+--+1234ab567";
	printf("'%s': %d\n", nb1, ft_atoi_base(nb1, decimal));
	char nb2[] = "--123456789";
	printf("'%s': %d\n", nb2, ft_atoi_base(nb2, decimal));
	char nb3[] = "2147483647";
	printf("'%s': %d\n", nb3, ft_atoi_base(nb3, decimal));
	char nb4[] = "   +---+-+0xxxxxx";
	printf("'%s': %d\n", nb4, ft_atoi_base(nb4, decimal));
	char nb5[] = " \f\n\r\t\v+-+-+-+-999\t897";
	printf("'%s': %d\n", nb5, ft_atoi_base(nb5, decimal));
	char nb6[] = "-2147483648";
	printf("'%s': %d\n", nb6, ft_atoi_base(nb6, decimal));


	printf("\nbinary: '%s'\n", binary);
	char nb7[] = " ---+--+1234ab567";
	printf("'%s': %d\n", nb1, ft_atoi_base(nb7, binary));
	char nb8[] = "--123456789";
	printf("'%s': %d\n", nb8, ft_atoi_base(nb8, binary));
	char nb9[] = "1001010101";
	printf("'%s': %d\n", nb9, ft_atoi_base(nb9, binary));
	char nb10[] = "   +---+-+0100101xxxxxx";
	printf("'%s': %d\n", nb10, ft_atoi_base(nb10, binary));
	char nb11[] = " \f\n\r\t\v+-+-+-+-111\t10101";
	printf("'%s': %d\n", nb11, ft_atoi_base(nb11, binary));
	char nb12[] = "-10101";
	printf("'%s': %d\n", nb12, ft_atoi_base(nb12, binary));

	printf("\nhex: '%s'\n", hex);
	char nb13[] = "3AF5";
	printf("'%s': %d\n", nb13, ft_atoi_base(nb13, hex));
	char nb14[] = "\t---+3AF5GH536";
	printf("'%s': %d\n", nb14, ft_atoi_base(nb14, hex));
	char nb15[] = "3AF5JKL";
	printf("'%s': %d\n", nb15, ft_atoi_base(nb15, hex));
	char nb16[] = "  ++++3AF5";
	printf("'%s': %d\n", nb16, ft_atoi_base(nb16, hex));

	printf("\ninvalid bases:\n");
	printf("'%s' in base '%s': %d\n", "123456789", "0", ft_atoi_base("123456789", "0"));
	printf("'%s' in base '%s': %d\n", "123456789", "+2", ft_atoi_base("123456789", "+2"));
	printf("'%s' in base '%s': %d\n", "123456789", "011", ft_atoi_base("123456789", "011"));
	printf("'%s' in base '%s': %d\n", "123456789", "", ft_atoi_base("123456789", ""));
}

void	print_sep(int ex_num)
{
	printf("\n*####################################### ex%02d\n", ex_num);
}


int	main(void)
{
	print_sep(0);
	ex00();
	print_sep(1);
	ex01();
	print_sep(2);
	ex02();
	print_sep(3);
	ex03();
	// print_sep(4);
	// ex04();
	print_sep(5);
	ex05();
}
