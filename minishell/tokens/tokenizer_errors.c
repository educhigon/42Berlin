/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:53:20 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/24 12:20:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	printf_token_error(t_shell *shell, t_token *token_ll)
{
	shell->current_cmd.status = 2;
	ft_putstr_fd("supershell: syntax error near unexpected token ", 2);
	if (token_ll->type == TOKEN_EOF)
		ft_putstr_fd("'newline'", 2);
	else
	{
		ft_putstr_fd("'", 2);
		ft_putstr_fd(token_ll->content, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd("\n", 2);
	return (2);
}

int	validate_token_syntax(t_token *token, t_token *last_token, t_shell *shell)
{
	if (token->type == TOKEN_PIPE)
	{
		if (!last_token)
			return (printf_token_error(shell, token));
		else if (last_token->type != TOKEN_WORD)
			return (printf_token_error(shell, token));
		else if (token->next->type == TOKEN_EOF)
			return (get_more_tokens(token, shell));
	}
	else if (token->type == TOKEN_REDIRECT_IN
		|| token->type == TOKEN_REDIRECT_HEREDOC
		|| token->type == TOKEN_REDIRECT_OUT_APP
		|| token->type == TOKEN_REDIRECT_OUT_TRUNC)
	{
		if (token->next->type != TOKEN_WORD)
			return (printf_token_error(shell, token->next));
	}
	return (0);
}

int	invalid_token(t_token *tokens, t_shell *shell)
{
	t_token	*last_token;
	int		validation_result;

	last_token = NULL;
	while (tokens->type != TOKEN_EOF)
	{
		validation_result = validate_token_syntax(tokens, last_token, shell);
		if (validation_result)
			return (validation_result);
		last_token = tokens;
		tokens = tokens->next;
	}
	if (last_token == NULL)
		return (1);
	return (0);
}
