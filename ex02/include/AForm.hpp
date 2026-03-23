/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:57:16 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 16:08:36 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	static const int _toSign;
	static const int _toExecute;

public:
	AForm();
	AForm(const std::string &name);
	~AForm();
	AForm &operator=(const AForm &other);
	AForm(const AForm &other);

	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getSignInfo() const;
	const int &getExecuteInfo() const;

	void beSigned(Bureaucrat &who);
	void execute(Bureaucrat const & executor) const;

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

std::ostream &operator<<(std::ostream &out, AForm &form);
