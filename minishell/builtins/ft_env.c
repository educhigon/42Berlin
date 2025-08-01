/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:34:30 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:34:31 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_env(t_shell *shell)
{
	char	**envp;

	envp = shell->envp;
	while (*envp)
	{
		printf("%s\n",*envp);
		envp++;
	}
	return (0);
}
