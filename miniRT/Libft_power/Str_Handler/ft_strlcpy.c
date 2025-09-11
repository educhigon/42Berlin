/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:51:57 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 11:22:47 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size - 1 && src[i] != '\0' && size != 0)
			dest[i] = src[i];
		i++;
	}
	if (size == 0)
		return (i);
	if (i >= size)
		dest[size - 1] = '\0';
	else
		dest[i] = '\0';
	return (i);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{

	printf("\n-------Test 0\n");
	printf("\nSRC = 5 char, DEST = 4 char, n = 4 char\n");
	unsigned int n0 = 4;

	char src0[] = "1234";
	printf("Source: %s \n", src0);
	char dest0[6];
	printf("Result number: %zu \n", ft_strlcpy(dest0, src0, n0));
	printf("Dest: '%s' \n", dest0);
	char srco[] = "1234";
	char desto[6];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto, srco, n0));
	printf("ORI Dest: '%s' \n", desto);


	printf("\n-------Test 1\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 8 char\n");
	unsigned int n1 = 8;

	char src1[] = "123456789 Trying different things!";
	printf("Source: %s \n", src1);
	char dest1[6];
	printf("Result number: %zu \n", ft_strlcpy(dest1, src1, n1));
	printf("Dest: '%s' \n", dest1);
	char srco1[] = "123456789 Trying different things!";
	char desto1[6];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto1, srco1, n1));
	printf("ORI Dest: '%s' \n", desto1);


	printf("\n-------Test 2\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 60 char\n");
	unsigned int n2 = 60;

	char src2[] = "123456789 Trying different things!";
	printf("Source: %s \n", src2);
	char dest2[60];
	printf("Result number: %zu \n", ft_strlcpy(dest2, src2, n2));
	printf("Dest: '%s' \n", dest2);
	char srco2[] = "123456789 Trying different things!";
	char desto2[60];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto2, srco2, n2));
	printf("ORI Dest: '%s' \n", desto2);


	printf("\n-------Test 3\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 10 char\n");
	unsigned int n3 = 10;

	char src3[] = "123456789 Trying different things!";
	printf("Source: %s \n", src3);
	char dest3[6];
	printf("Result number: %zu \n", ft_strlcpy(dest3, src3, n3));
	printf("Dest: '%s' \n", dest3);
	char srco3[] = "123456789 Trying different things!";
	char desto3[6];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto3, srco3, n3));
	printf("ORI Dest: '%s' \n", desto3);


	printf("\n-------Test 4\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 3 char\n");
	unsigned int n4 = 3;

	char src4[] = "123456789 Trying different things!";
	printf("Source: %s \n", src4);
	char dest4[6];
	printf("Result number: %zu \n", ft_strlcpy(dest4, src4, n4));
	printf("Dest: '%s' \n", dest4);
	char srco4[] = "123456789 Trying different things!";
	char desto4[6];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto4, srco4, n4));
	printf("ORI Dest: '%s' \n", desto4);


	printf("\n-------Test 5\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 50 char\n");
	unsigned int n5 = 50;

	char src5[] = "123456789 Trying different things!";
	printf("Source: %s \n", src5);
	char dest5[60];
	printf("Result number: %zu \n", ft_strlcpy(dest5, src5, n5));
	printf("Dest: '%s' \n", dest5);
	char srco5[] = "123456789 Trying different things!";
	char desto5[60];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto5, srco5, n5));
	printf("ORI Dest: '%s' \n", desto5);


	printf("\n-------Test 6\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 65 char\n");
	unsigned int n6 = 65;

	char src6[] = "123456789 Trying different things!";
	printf("Source: %s \n", src6);
	char dest6[60];
	printf("Result number: %zu \n", ft_strlcpy(dest6, src6, n6));
	printf("Dest: '%s' \n", dest6);
	char srco6[] = "123456789 Trying different things!";
	char desto6[60];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto6, srco6, n6));
	printf("ORI Dest: '%s' \n", desto6);

	printf("\n-------Test 7\n");
	printf("\nSRC = 5 char, DEST = 0 char, n = 1 char\n");
	unsigned int n7 = 1;

	char src7[] = "1234";
	printf("Source: %s \n", src7);
	char dest7[0];
	printf("Result number: %zu \n", ft_strlcpy(dest7, src7, n7));
	printf("Dest: '%s' \n", dest7);
	char srco7[] = "1234";
	char desto7[0];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto7, srco7, n7));
	printf("ORI Dest: '%s' \n", desto7);

	printf("\n-------Test 8\n");
	printf("\nSRC = 0 char, DEST = 6 char, n = 6 char\n");
	unsigned int n8 = 6;

	char src8[] = "";
	printf("Source: %s \n", src8);
	char dest8[6];
	printf("Result number: %zu \n", ft_strlcpy(dest8, src8, n8));
	printf("Dest: '%s' \n", dest8);
	char srco8[] = "";
	char desto8[6];
	printf("ORIGINAL - Result number: %zu \n", strlcpy(desto8, srco8, n8));
	printf("ORI Dest: '%s' \n", desto8);

	printf("\n-------Test 9\n");
	printf("\nSRC = NULL, DEST = 6 char, n = 6 char\n");
	unsigned int n9 = 6;

	char *src9 = NULL;
	printf("Source: %s \n", src9);
	char dest9[6];
	printf("Result number: %zu \n", ft_strlcpy(dest9, src9, n9));
	printf("Dest: '%s' \n", dest9);
	char *srco9 = NULL;
	char desto9[6];
	// printf("ORIGINAL - Result number: %zu \n", strlcpy(desto9, srco9, n9));
	printf("ORI Dest: '%s' \n", desto9);
	
	printf("\n-------Test 10\n");
	printf("\nSRC = 35 char, DEST = NULL, n = 10 char\n");
	unsigned int n10 = 10;

	char src10[] = "123456789 Trying different things!";
	printf("Source: %s \n", src10);
	char *dest10 = NULL;
	printf("Result number: %zu \n", ft_strlcpy(dest10, src10, n10));
	printf("Dest: '%s' \n", dest10);
	char srco10[] = "123456789 Trying different things!";
	char *desto10 = NULL;
	// printf("ORIGINAL - Result number: %zu \n", strlcpy(desto10, srco10, n10));
	printf("ORI Dest: '%s' \n", desto10);

}
*/