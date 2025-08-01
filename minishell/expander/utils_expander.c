/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:45:38 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:45:54 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_expander(t_expander *expander, char *arg,
	t_token **expanded_args_ll)
{
	expander->quote_type = NO_QUOTE;
	expander->buf = malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (!expander->buf)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	expander->buf_size = ft_strlen(arg) + 1;
	expander->buf_i = 0;
	expander->expanded_args_ll = expanded_args_ll;
}

char	*ft_getenv(char **envp, char *search_term)
{
	int			i;
	size_t		len;

	i = 0;
	len = ft_strlen(search_term);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], search_term, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	**convert_ll_to_array(t_token *args_ll)
{
	char	**args;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * (ft_lstsize_token(args_ll) + 1));
	if (!args)
		return (NULL);
	while (args_ll && args_ll->content)
	{
		args[i] = ft_strdup(args_ll->content);
		args_ll = args_ll->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	expand_buffer_by(t_expander *expander, int additional_len)
{
	char	*new_buf;
	int		new_size;

	new_size = expander->buf_size + additional_len;
	if (new_size < expander->buf_size)
		new_size = expander->buf_size;
	new_buf = malloc(new_size);
	if (!new_buf)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_buf, expander->buf, expander->buf_i);
	new_buf[expander->buf_i] = '\0';
	free(expander->buf);
	expander->buf = new_buf;
	expander->buf_size = new_size;
}
