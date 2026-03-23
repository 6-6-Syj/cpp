/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 15:18:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	static const int _toSign;
	static const int _toExecute;

public:
	Form();
	Form(const std::string &name);
	~Form();
	Form &operator=(const Form &other);
	Form(const Form &other);

	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getSignInfo() const;
	const int &getExecuteInfo() const;

	void beSigned(Bureaucrat &who);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form &form);
