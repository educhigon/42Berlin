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

//Main
int		main(void);

// Translation
void	add_signal(t_list **lst, char *digit);
void	translate_char(t_list *list, int start, int end);
char	*get_binary_num_from_signals(t_list *list, int start, int end);
int		convert_binary_str_to_int(char *str);

#endif