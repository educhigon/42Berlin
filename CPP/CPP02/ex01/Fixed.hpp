/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:06:57 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/23 17:10:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

	public:
		Fixed();
		Fixed(const int v);
		Fixed(const float v);

		~Fixed();

		Fixed(const Fixed &obj);

		Fixed& operator=(const Fixed& other);

		int getRawBits( void ) const;
		void setRawBits( int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	protected:

	private:
		int _fixed_point;
		const static int _num_bits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
