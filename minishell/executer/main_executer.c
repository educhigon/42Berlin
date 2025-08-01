/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:43:13 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 15:40:03 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	execute_tree(t_astnode *tree, t_shell *shell)
{
	int	exec_ans;

	exec_ans = 0;
	if (tree->type == AST_PIPELINE)
		exec_ans = exec_pipe(tree, shell);
	else if (tree->type == AST_REDIRECT)
		exec_ans = exec_redirect(tree, shell);
	else if (tree->type == AST_COMMAND)
		exec_ans = exec_command(tree, shell);
	else if (tree->type == AST_ERROR)
		ft_printf(RED"Error in execution\n"RST);
	return (exec_ans);
}

int	execute(t_astnode *tree, t_shell *shell)
{
	int	exec_ans;

	exec_ans = 0;
	shell->current_cmd.input_fd = 0;
	shell->current_cmd.input_type = 0;
	shell->current_cmd.output_fd = 0;
	shell->current_cmd.output_type = 0;
	exec_ans = execute_tree(tree, shell);
	return (exec_ans);
}
