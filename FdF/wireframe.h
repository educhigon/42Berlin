/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:31 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 15:57:17 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_H
# define WIREFRAME_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
// # include <mlx.h>
# include "Libft_power/ft_printf/ft_printf.h"
# include "libft.h"

typedef struct	s_vars {
	void	*ptr;
	void	*win;
}				t_vars;

//Main
int	main(void);

#endif
