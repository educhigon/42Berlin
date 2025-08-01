/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:50:00 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 15:37:55 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**copy_env(char **env)
{
	int		env_size;
	int		i;
	char	**env_copy;

	env_size = ft_strlen_st_st((const char **)env);
	env_copy = malloc ((env_size + 1) * sizeof(char *));
	i = 0;
	while (i < env_size)
	{
		env_copy[i] = malloc ((ft_strlen(env[i]) + 1) * sizeof(char));
		ft_strlcpy(env_copy[i], env[i], ft_strlen(env[i]) + 1);
		i++;
	}
	env_copy[i] = 0;
	return (env_copy);
}

void	print_error_redir(t_shell *evment)
{
	ft_putstr_fd("supershell: ", 2);
	ft_putstr_fd(evment->current_cmd.err_text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(evment->current_cmd.status), 2);
	ft_putstr_fd("\n", 2);
	return ;
}

int	print_errors(t_shell *shell, char *cmd, char *error_text, int status)
{
	ft_putstr_fd("supershell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_text, 2);
	ft_putstr_fd("\n", 2);
	shell->current_cmd.status = status;
	if (shell->tree)
		free_tree(shell->tree);
	if (shell->token_ll_or)
		ft_lstclear_token(&shell->token_ll_or, del_content_token);
	return (status);
}

void	add_history_entry(t_token *token_ll_or)
{
	char	**test;
	char	*test2;
	char	*trimmed;

	test = convert_ll_to_array(token_ll_or);
	test2 = ft_strjoin_st_st(test);
	if (test2 && test2[0] == ' ')
		trimmed = test2 + 1;
	else
		trimmed = test2;
	add_history(trimmed);
	ft_split_free(test);
	free(test2);
}
