/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:37:57 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/02 19:16:56 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_comb(void);

int	main(void)
{
	ft_print_comb();
}

int	printing(char i, char j, char k, char m)
{
	int	comma;
	int	space;

	comma = 44;
	space = 32;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &space, 1);
	write(1, &k, 1);
	write(1, &m, 1);
	if (i == '7' && j == '8' && k == '9')
	{
		return (0);
	}
	write(1, &comma, 1);
	write(1, &space, 1);
}

void	ft_print_comb(void)
{
	int	f1;
	int	f2;
	int	s1;
	int	s2;

	f1 = '0';
	f2 = '0';
	while (f1 <= '9')
	{
		s2 = f2 + 1;
		if (s2 == ':')
		{
			if (s1 == ':')
			{
				f2 = f2 + 1;
			}
			s1 = s1 + 1;
			s2 = f2 + 1;
		}
		i++;
	}
}
