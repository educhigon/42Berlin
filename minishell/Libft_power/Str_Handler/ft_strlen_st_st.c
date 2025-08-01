/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_st_st.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:54:52 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 10:50:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen_st_st(const char **str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}
