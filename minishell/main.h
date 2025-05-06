/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 16:51:18 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 16:51:18 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

#define Y		"\033[1;33m"
#define G		"\033[1;32m"
#define C		"\033[1;36m"
#define RED		"\033[1;31m"
#define RST		"\033[0m"


#endif