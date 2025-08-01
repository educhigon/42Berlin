/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:41:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:41:56 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	expand_tilde(t_expander *expander, char *arg, t_shell *shell)
{
	char	*home;
	int		consumed;
	int		home_len;

	consumed = 1;
	home_len = 0;
	home = ft_getenv(shell->envp, "HOME");
	if ((*(arg + 1) == '/' || *(arg + 1) == '\0') && home)
	{
		home_len = ft_strlen(home);
		expand_buffer_by(expander, home_len);
		while (*home)
			expander->buf[expander->buf_i++] = *home++;
	}
	else
		expander->buf[expander->buf_i++] = *arg;
	return (consumed);
}
