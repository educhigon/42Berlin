/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:45:58 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:46:02 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	cleanup_expander(t_expander *expander)
{
	if (expander && expander->buf)
	{
		free(expander->buf);
		expander->buf = NULL;
	}
}
