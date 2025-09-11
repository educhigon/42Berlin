/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:02 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 22:35:10 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
char			*ft_substr(char const *s, unsigned int start,
					unsigned long len);
unsigned long	ft_strlen3(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strchr2(char *str, int c);
int				count_lines(int fd);

#endif
