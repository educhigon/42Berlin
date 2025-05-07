/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:34:23 by edugonza          #+#    #+#             */
/*   Updated: 2025/05/07 15:16:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line/get_next_line.h"
# include "get_next_line/get_next_line_bonus.h"
# include "ft_printf/ft_printf.h"
# include <stddef.h>

// Checkers
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_str_is_alpha(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);

// Converters
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*ft_itoa(int n);

// Math
void			ft_div_mod(int a, int b, int *div, int *mod);
int				ft_fibonacci(int index);
int				ft_find_next_prime(int nb);
int				ft_is_prime(int nb);
int				ft_iterative_factorial(int nb);
int				ft_iterative_power(int nb, int power);
int				*ft_range(int min, int max);
int				ft_recursive_factorial(int nb);
int				ft_recursive_power(int nb, int power);
void			ft_rev_int_tab(int *tab, int size);
void			ft_sort_int_tab(int *tab, int size);
int				ft_sqrt(int nb);

// Mem_Handler
void			ft_bzero(void *s, unsigned long n);
void			*ft_calloc(unsigned long nmemb, unsigned long size);
void			*ft_memchr(const void *s, int c, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
void			*ft_memcpy(void *dest, const void *src, unsigned long n);
void			*ft_memmove(void *dest, const void *src, unsigned long n);
void			*ft_memset(void *s, int c, unsigned long n);

// Printers
void			ft_print_numbers(void);
void			ft_print_reverse_alphabet(void);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr_non_printable(char *str);

// Str_Handler
char			**ft_split(char const *s, char c);
void			ft_split_free(char **s);
char			*ft_strchr(char *str, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned long	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned long	ft_strlcpy(char *dest, const char *src, unsigned int size);
unsigned long	ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(char *big, char *little, unsigned long len);
char			*ft_strrchr(char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start,
					unsigned long len);

// Str_Modifiers
char			*ft_strcapitalize(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

// List
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

#endif
