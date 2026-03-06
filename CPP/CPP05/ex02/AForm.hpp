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

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;


	public:
		// AForm();
		AForm(std::string _name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm& operator=(const AForm& other);
		AForm(const AForm &obj);


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

		class NotSignedException : public std::exception {
			virtual const char* what() const throw() {
				return "Form is not signed!";
			}
		};

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0; // Pure virtual function, making AForm an abstract class
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
