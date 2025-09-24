/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:06:57 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/23 15:25:04 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw);

	protected:

	private:
		int _fixed_point;
		const static int _num_bits = 8;

};

#endif
