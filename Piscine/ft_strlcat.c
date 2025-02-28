/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:52:23 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/18 11:36:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(char *arr)
{
	int	size;

	size = 0;
	while (arr[size] != '\0')
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = get_size(dest);
	size_src = get_size(src);
	if (size == 0)
		return (size_src);
	i = size_dest;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
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
#include <stdio.h>
#include <bsd/string.h>

int main()
{

	char src_or[] = "0123456789";
	char dest_or[5] = "abcd";
	printf("Len of function is: '%zu'\n", strlcat(dest_or, src_or, 0));
	printf("ORIGINAL -- Final dest: '%s'\n", dest_or);
	
	char src_edu[] = "0123456789";
	char dest_edu[5] = "abcd";
	printf("Len of function is: '%u'\n", ft_strlcat(dest_edu, src_edu, 0));
	printf("EDU -- Final dest: '%s'\n", dest_edu);

}
*/