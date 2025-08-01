/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:53:42 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/24 11:09:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*copy_word(char *source)
{
	char	*dest;
	int		len;

	len = ft_strlen(source);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, source, len + 1);
	return (dest);
}

void	build_word(t_token *tok, t_astnode *tree)
{
	char	**cmd;
	int		len;
	int		i;

	if (tree->s_command.argv == NULL)
		len = 0;
	else
		len = ft_strlen_char_char(tree->s_command.argv);
	len++;
	cmd = malloc((len + 1) * sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		cmd[i] = copy_word(tree->s_command.argv[i]);
		i++;
	}
	cmd[i] = copy_word(tok->content);
	cmd[i + 1] = NULL;
	if (tree->s_command.argv != NULL)
		ft_split_free(tree->s_command.argv);
	tree->s_command.argv = cmd;
	return ;
}

void	build_name(t_token *tok, t_astnode *tree)
{
	char	**filename;
	int		len;
	int		i;

	if (tree->s_redirect.filename == NULL)
		len = 0;
	else
		len = ft_strlen_char_char(tree->s_redirect.filename);
	len++;
	filename = malloc((len + 1) * sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		filename[i] = copy_word(tree->s_redirect.filename[i]);
		i++;
	}
	filename[i] = copy_word(tok->content);
	filename[i + 1] = NULL;
	if (tree->s_redirect.filename != NULL)
		ft_split_free(tree->s_redirect.filename);
	tree->s_redirect.filename = filename;
	return ;
}
