#include "minishell.h"

void    init_expander(t_expander *expander, char *str, t_list**expanded_args)
{
    expander->context = NO_QUOTE;
    expander->i = 0;
    expander->buf = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!expander->buf)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    expander->buf_size = ft_strlen(str) + 1;
    expander->buf_i = 0;
    expander->tokens = expanded_args;
    expander->empty_quotes = 0;
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t	i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}