/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:
		std::string	_name;
		int	_grade;

	public:
		// Bureaucrat();
		Bureaucrat(std::string _name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat(const Bureaucrat &obj);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void operator<<(const Bureaucrat& other);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
				return "Grade is too high!";
			}
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw() {
				return "Grade is too low!";
			}
		};

};

#endif
