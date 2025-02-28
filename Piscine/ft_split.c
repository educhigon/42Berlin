/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:55:05 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 17:05:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(char *str, char *charset)
{
	int i;
	int j;
	int count_words;

	count_words = 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0')
		{
			if (charset[j] == str[i])
			{
				count_words++;
				break;	
			}
			j++;
		}
		i++;
	}
	return (count_words);
}

int	num_chars_in_word(char *str,char *charset, char **new_string)
{
	int i;
	int j;
	int count_words;
	int char_count_in_word;
	int flag;
	int str_w;

	flag = 0;
	str_w = 0;
	count_words = 1;
	while (str[i] != '\0')
	{
		j = 0;
		flag = 0;
		while (charset[j] != '\0')
		{
			if (charset[j] == str[i])
			{
				if (char_count_in_word != 0)
				{
					new_string[str_w] = (char *)malloc((char_count_in_word + 1)* sizeof(char));
					char_count_in_word = 0;
					str_w++;
				}
				flag = 1;
			}
			j++;
		}
		if (!flag)
			char_count_in_word++;
		i++;
	}
	return (count_words);
}

void	build_new_string(char **new_string, char *charset, char *str, int i)
{
	int	char_count_in_word;
	int	num_charset;
	int	i;
	int	j;

	char_count_in_word = num_chars_in_word(str, i);
		// counting the null terminator
	num_charset = num_chars_in_word(charset);
	j = 0;
	while (j < num_charset)
	{
		new_string[i][j] = charset[j];
		j++;
	}
	j = 0;
	while (j < char_count_in_word)
	{
		new_string[i][j] = str[j];
		j++;
	}
	while (j < num_charset)
	{
		new_string[i][j] = charset[j];
		j++;
	}
	new_string[i][j] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		num_words;
	int		num_charset;
	int		char_count_in_word;
	char	**new_string;
	int		i;
	int		j;

	num_words = count_words(str, charset);
	// num_charset = num_chars_in_word(charset);
	new_string = (char **)malloc(num_words * sizeof(char));
	i = 0;
	while (i < num_words)
	{
		char_count_in_word = num_chars_in_word(str, i, new_string);
			// counting the null terminator
		build_new_string(new_string, charset, str, i);
		i++;
	}
}
