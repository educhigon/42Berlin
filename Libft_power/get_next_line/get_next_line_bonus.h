/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:19:59 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 22:35:08 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char			*get_next_line(int fd);
char			*ft_substr_bonus(char const *s, unsigned int start,
					unsigned long len);
unsigned long	ft_strlen2_bonus(const char *str);
char			*ft_strjoin_bonus(char const *s1, char const *s2);
int				ft_strchr_bonus(char *str, int c);

#endif
