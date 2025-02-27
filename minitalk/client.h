/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:11:36 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-26 17:11:36 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "libft.h"

//Main
int			main(int ac, char *av[]);

// Helpers
char *ft_putchar_base(char num);
char *ft_putnbr_base(int num);


#endif