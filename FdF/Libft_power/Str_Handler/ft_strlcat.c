/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:51:18 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 11:22:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = size_dest;
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < size_dest)
		return (size_src + size);
	return (size_dest + size_src);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int main()
{
printf("\n-------Test 0\n");
printf("\nSRC = 10 char, DEST = 4 char, n = 0 char\n");
char src0[] = "0123456789";
printf("Source: %s \n", src0);
char dest0[5] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest0, src0, 0));
printf("Dest: '%s' \n", dest0);
char srco0[] = "0123456789";
char desto0[5] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto0, srco0, 0));
printf("ORI Dest: '%s' \n", desto0);

// Edge cases
printf("\n-------Test 1\n");
printf("\nSRC = 10 char, DEST = 4 char, n = 3 char\n");
char src1[] = "0123456789";
printf("Source: %s \n", src1);
char dest1[5] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest1, src1, 3));
printf("Dest: '%s' \n", dest1);
char srco1[] = "0123456789";
char desto1[5] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto1, srco1, 3));
printf("ORI Dest: '%s' \n", desto1);

printf("\n-------Test 2\n");
printf("\nSRC = 10 char, DEST = 10 char, n = 10 char\n");
char src2[] = "0123456789";
printf("Source: %s \n", src2);
char dest2[10] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest2, src2, 10));
printf("Dest: '%s' \n", dest2);
char srco2[] = "0123456789";
char desto2[10] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto2, srco2, 10));
printf("ORI Dest: '%s' \n", desto2);

printf("\n-------Test 3\n");
printf("\nSRC = 0 char, DEST = 10 char, n = 10 char\n");
char src3[] = "";
printf("Source: '%s' \n", src3);
char dest3[10] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest3, src3, 10));
printf("Dest: '%s' \n", dest3);
char srco3[] = "";
char desto3[10] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto3, srco3, 10));
printf("ORI Dest: '%s' \n", desto3);

printf("\n-------Test 4\n");
printf("\nSRC = 10 char, DEST = 0 char, n = 5 char\n");
char src4[] = "0123456789";
printf("Source: %s \n", src4);
char dest4[0] = "";
printf("Len of function is: '%zu'\n", ft_strlcat(dest4, src4, 5));
printf("Dest: '%s' \n", dest4);
char srco4[] = "0123456789";
char desto4[0] = "";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto4, srco4, 5));
printf("ORI Dest: '%s' \n", desto4);

printf("\n-------Test 5\n");
printf("\nSRC = 10 char, DEST = 10 char, n = 1 char\n");
char src5[] = "0123456789";
printf("Source: %s \n", src5);
char dest5[10] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest5, src5, 1));
printf("Dest: '%s' \n", dest5);
char srco5[] = "0123456789";
char desto5[10] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto5, srco5, 1));
printf("ORI Dest: '%s' \n", desto5);

printf("\n-------Test 6\n");
printf("\nSRC = 10 char, DEST = 10 char, n = 20 char\n");
char src6[] = "0123456789";
printf("Source: %s \n", src6);
char dest6[10] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest6, src6, 20));
printf("Dest: '%s' \n", dest6);
char srco6[] = "0123456789";
char desto6[10] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto6, srco6, 20));
printf("ORI Dest: '%s' \n", desto6);

printf("\n-------Test 7\n");
printf("\nSRC = NULL, DEST = 10 char, n = 5 char\n");
char *src7 = NULL;
printf("Source: (null)\n");
char dest7[10] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(dest7, src7, 5));
printf("Dest: '%s' \n", dest7);
// char *srco7 = NULL;
char desto7[10] = "abcd";
// printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto7, srco7, 5));
printf("ORI Dest: '%s' \n", desto7);

printf("\n-------Test 8\n");
printf("\nSRC = 10 char, DEST = NULL, n = 10 char\n");
char src8[] = "0123456789";
printf("Source: %s \n", src8);
char *dest8 = NULL;
printf("Len of function is: '%zu'\n", ft_strlcat(dest8, src8, 10));
printf("Dest: '%s' \n", dest8);
// char srco8[] = "0123456789";
char *desto8 = NULL;
// printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(desto8, srco8, 10));
printf("ORI Dest: '%s' \n", desto8);

printf("\n-------Test 8\n");
printf("\nSRC = 10 char, DEST = NULL, n = 10 char\n");
char srcofra[] = "0123456789";
char destfra[] = "abcd";
printf("Len of function is: '%zu'\n", ft_strlcat(destfra, srcofra, 0));
printf("Dest: '%s' \n", destfra);
char destofra[] = "abcd";
printf("ORIGINAL - Len of function is: '%zu'\n", strlcat(destofra, srcofra, 0));
printf("ORI Dest: '%s' \n", destofra);

}

*/