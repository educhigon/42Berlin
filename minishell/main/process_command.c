/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:52:35 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 16:20:58 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	validate_and_prepare_tokens(t_shell *evment, t_token *token_ll)
{
	if (invalid_token(token_ll, evment))
	{
		ft_lstclear_token(&evment->token_ll_or, del_content_token);
		return (0);
	}
	add_history_entry(evment->token_ll_or);
	return (1);
}

static int	parse_and_execute(t_shell *evment, t_token *token_ll)
{
	t_parser	parser;
	int			exec_ans;

	parser.current = token_ll;
	evment->tree = parse_line(&parser, NULL, &token_ll);
	if (!evment->tree)
		return (0);
	evment->tree = expand_tree(evment->tree, evment);
	evment->current_cmd.status = 0;
	exec_ans = execute(evment->tree, evment);
	if (!exec_ans)
		free_tree(evment->tree);
	return (exec_ans);
}

static void	cleanup_tokens_if_needed(t_shell *evment, int exec_ans)
{
	if (!exec_ans)
		ft_lstclear_token(&evment->token_ll_or, del_content_token);
}

int	process_command(t_shell *evment, char *line)
{
	t_token	*token_ll;
	int		exec_ans;

	token_ll = tokenize(line, evment);
	if (!token_ll)
		return (0);
	evment->token_ll_or = token_ll;
	if (!validate_and_prepare_tokens(evment, token_ll))
		return (0);
	exec_ans = parse_and_execute(evment, token_ll);
	cleanup_tokens_if_needed(evment, exec_ans);
	return (exec_ans);
}
