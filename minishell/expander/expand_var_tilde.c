#include "minishell.h"


void	expand_variable(t_expander *expander, char *str)
{
	char    *value;

	if (*(str + 1) == '?')
		expand_last_status(expander, str);
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
//buggy, it fucks up when its ~/something
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
		expander->i = -1;//rese
	}
	else
		expander->buf[expander->buf_i++] = *str;
}


void	expand_last_status(t_expander *expander, char *str)
{
  //how to access the last status
	return; 
}