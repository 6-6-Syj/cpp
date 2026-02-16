/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:42:18 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/16 16:17:27 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	const std::string& getName();
	const int& getGrade();
	
	void incrementGrade();
	void decrementGrade();
	
	class GradeTooHighException: public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat test);