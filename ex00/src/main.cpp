/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 15:24:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void copyAndAssign()
{
	std::cout << "\n=== COPY & ASSIGNMENT ===" << std::endl;

	try
	{
		Bureaucrat a("CopySource", 42);
		Bureaucrat b(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		Bureaucrat c("AssignTarget", 100);
		c = a;
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Copy/Assign test: " << e.what() << std::endl;
	}
}

static void valid()
{
	std::cout << "\n=== VALID BUREAUCRATS ===" << std::endl;

	try
	{
		Bureaucrat ok("isValid", 150);
		std::cout << ok << std::endl;

		Bureaucrat valid("IsValid", 1);
		std::cout << valid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat isValid: " << e.what() << std::endl;
	}
}

static void invalid()
{
	std::cout << "\n=== INVALID GRADE IN CONSTRUCTOR ===" << std::endl;

	try
	{
		Bureaucrat not_ok("null", 0);
		std::cout << not_ok << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat null: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat not_ok("tooLow", 180);
		std::cout << not_ok << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat tooLow: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat not_ok("negativeInput", -155);
		std::cout << not_ok << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat negativeInput: " << e.what() << std::endl;
	}
}

static void decrement()
{
	std::cout << "\n=== DECREMENT GRADE TESTS ===" << std::endl;

	try
	{
		Bureaucrat ok("decrementTest", 145);
		for (int i = 0; i < 6; i++)
		{
			ok.decrementGrade();
			std::cout << ok << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat decrementTest: " << e.what() << std::endl;
	}
}

static void increment()
{
	std::cout << "\n=== INCREMENT GRADE TESTS ===" << std::endl;

	try
	{
		Bureaucrat ok("incrementTest", 6);
		for (int i = 0; i < 6; i++)
		{
			ok.incrementGrade();
			std::cout << ok << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat incrementTest: " << e.what() << std::endl;
	}
}

int main()
{
	copyAndAssign();
	valid();
	invalid();
	decrement();
	increment();

	return 0;
}
