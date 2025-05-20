/*-------------------------------HEADER PART-----------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
typedef enum e_exp_context
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_exp_context;
typedef struct s_expander
{
	t_exp_context	context;
	int 			i;
	char 			*buf;
	int 			buf_size;
	int 			buf_i;
	t_list			**tokens;
	int 			empty_quotes;
}	t_expander;

size_t	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_expander(t_expander *expander, char *str, t_list**expanded_args);
void	expand_one_arg(char *str, t_list **expanded_args, char **envp);
void	no_quote_state(t_expander *expander, char *str, char **envp);
void	single_quote_state(t_expander *expander, char *str, char **envp);
void	double_quote_state(t_expander *expander, char *str, char **envp);
void	expand_variable(t_expander *expander, char *str, char **envp);
void	expand_tilde(t_expander *expander, char *str, char **envp);
/*-------------------------------HEADER END-----------------------------------*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	return (len);
}
void init_expander(t_expander *expander, char *str, t_list**expanded_args)
{
    expander->context = NO_QUOTE;
    expander->i = 0;
    expander->buf = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!expander->buf)
    {
        perror("malloc");
        exit(1);
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
void	expand_one_arg(char *str, t_list **expanded_args, char **envp)
{
	t_expander expander;


	init_expander(&expander, str, expanded_args);
	while(*str)
	{
		if (expander.context == NO_QUOTE)
			no_quote_state(&expander, str, envp);
		else if (expander.context == SINGLE_QUOTE)
			single_quote_state(&expander, str, envp);
		else if (expander.context == DOUBLE_QUOTE)
			double_quote_state(&expander, str, envp);
		if (*str)
			str++;
	}
	if (expander.context != NO_QUOTE)
	{
		printf("quote is not closed\n");
		//free the allocated memory in expander
		exit(1);
	}
	//function to add the buffer to the linked list
	//debug fn to print the linked list
	printf("the buffer: %s\n", expander.buf);
}

void	no_quote_state(t_expander *expander, char *str, char **envp)
{
	if (*str == '~')
		expand_tilde(expander, str, envp);
	else if (*str == '$')
		expand_variable(expander, str, envp);
	else if (*str == ' ')
		//function to add the buffer to the linked list
		//reset the buffer
        return;
	else if (*str == '\"')
		expander->context = DOUBLE_QUOTE;
	else if (*str == '\'')
		expander->context = SINGLE_QUOTE;
	else if (*str == '\\')
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
		str++;
	}
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
}

void	single_quote_state(t_expander *expander, char *str, char **envp)
{
	if (*str == '\'')
		expander->context = NO_QUOTE;
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	} 
}
//escaping character still needs to be handled
void	double_quote_state(t_expander *expander, char *str, char **envp)
{
	if (*str == '$')
	{
		//expand variable function
		//add buffer to the linked list 
		// reset the buffer
	}
	else if (*str == '\"')
		expander->context = NO_QUOTE;
	else if (*str == '\\' && (*(str + 1) == '\"' || *(str + 1) == '\\'))
	{
		str++;
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
	else
	{
		expander->buf[expander->buf_i] = *str;
		expander->buf_i++;
	}
}
void	expand_variable(t_expander *expander, char *str, char **envp)
{
	char    *value;

	if (*(str + 1) == '?')
        return;
		//expand_last_status(expander, str);
	else if (expander->context == NO_QUOTE && (*(str + 1) == '\"' || *(str + 1) == '\''))
		return;
	else
	{
		//look for environment variable & assign it to value
		if (!value)
			return ;
		//check for something i dint know
		//add it to buffer
	}
}
void	expand_tilde(t_expander *expander, char *str, char **envp)
{
	char	*home;

	home = NULL;
	// Check if it's "~" or "~/..."
	if (*(str + 1) == '/' || *(str + 1) == '\0')
	{
		while (*envp)
		{
			if (ft_strncmp(*envp, "HOME=", 5) == 0)
			{
				home = *envp + 5;
				break ;
			}
			envp++;
		}
		if (!home)
			return ;
		while (*home)
			expander->buf[expander->buf_i++] = *home++;
		str++;
		while (*str)
			expander->buf[expander->buf_i++] = *str++;
	}
	else
		expander->buf[expander->buf_i++] = *str;
}

int main (int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    char *str = "~/def";
    t_list *expanded_args = NULL;

    expand_one_arg(str, &expanded_args, envp);
    return (0);
}


//searches through the provided environment variable array (envp) 
//for the contents of search_term
static char	*ft_getenv(char **envp, char* search_term)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], search_term, ft_strlen(search_term)) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}