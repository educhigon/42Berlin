/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:12:59 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-26 17:12:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

extern t_list *list;

//Main
int			main();

// Translation
void	add_signal(t_list **lst, char *digit);
void	translate_char(t_list *list, int start, int end);
int		find_num_signals(t_list *list);

void	printf_nodes(t_list *list, int size, int start, int end);

// Helpers
// char *ft_putchar_base_reverse(char *num);

#endif