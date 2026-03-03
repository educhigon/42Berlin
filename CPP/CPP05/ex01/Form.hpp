/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;


	public:
		// Form();
		Form(std::string _name, int gradeToSign, int gradeToExecute);
		~Form();
		Form& operator=(const Form& other);
		Form(const Form &obj);


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

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);

};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
