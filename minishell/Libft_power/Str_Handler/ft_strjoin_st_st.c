/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_st_st.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:44 by edugonza          #+#    #+#             */
/*   Updated: 2025/05/23 20:10:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_strjoin_st_st(char **s)
{
	int		i;
	char	*temp;
	char	*merge;

	if (!s)
		return (NULL);
	temp = NULL;
	merge = malloc (sizeof(char));
	merge[0] = '\0';
	i = 0;
	while (s[i] != 0)
	{
		temp = ft_strjoin(merge, " ");
		free(merge);
		merge = temp;
		temp = ft_strjoin(merge, s[i]);
		free(merge);
		merge = temp;
		i++;
	}
	return (merge);
}
