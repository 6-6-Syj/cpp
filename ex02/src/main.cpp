/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 15:37:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void copyAndAssign()
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

void valid()
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

void invalid()
{
	std::cout << "\n=== INVALID GRADE IN CONSTRUCTOR ===" << std::endl;

	try
	{
		Bureaucrat not_ok("null", 0);
		std::cout << not_ok << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat null: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat not_ok("tooLow", 180);
		std::cout << not_ok << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat tooLow: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat not_ok("negativeInput", -155);
		std::cout << not_ok << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat negativeInput: " << e.what() << std::endl;
	}
}

void decrement()
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
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat decrementTest: " << e.what() << std::endl;
	}
}

void increment()
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
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat incrementTest: " << e.what() << std::endl;
	}
}

void testFirstEx()
{
	copyAndAssign();
	valid();
	invalid();
	decrement();
	increment();
}

void constructorAndCopy()
{
	std::cout << "\n=== FORM BASICS ===" << std::endl;

	Form form1;
	std::cout << form1;

	Form form2("Contrat");
	std::cout << form2 << std::endl;

	std::cout << "Sign grade required: " << form2.getSignInfo() << std::endl;
	std::cout << "Exec grade required: " << form2.getExecuteInfo() << std::endl;

	std::cout << "\n=== COPY FORM ===" << std::endl;

	Form original("Original");
	Bureaucrat signer("Signer", 90);
	signer.signForm(original);

	Form copy(original);
	std::cout << "Original: " << original;
	std::cout << "Copy: " << copy << std::endl;
}

void signSuccess()
{
	std::cout << "\n=== SUCCESSFUL SIGNATURE (grade 90 <= 100) ===" << std::endl;
	Bureaucrat capable("John", 90);
	Form contrat("ImportantContract");

	std::cout << "Before: " << contrat;
	capable.signForm(contrat);
	std::cout << "After: " << contrat << std::endl;
}

void signFail()
{
	std::cout << "\n=== FAILED SIGNATURE (grade 120 > 100) ===" << std::endl;
	Bureaucrat cant("Paul", 120);
	Form contrat("ImportantContract");

	std::cout << "Bureaucrat: " << cant << std::endl;
	cant.signForm(contrat);
	std::cout << contrat << std::endl;
}

void multipleSign()
{
	std::cout << "\n=== MULTIPLE SIGNATURES ===" << std::endl;
	Form contrat("TestContract");

	Bureaucrat tooLow("TooLow", 140);
	Bureaucrat perfect("Perfect", 80);

	tooLow.signForm(contrat);
	perfect.signForm(contrat);
	perfect.signForm(contrat);
}

void boundaryCases()
{
	std::cout << "\n=== BOUNDARY CASES ===" << std::endl;

	Bureaucrat exact("lvl100", 100);
	Form form("Form");
	exact.signForm(form);

	Bureaucrat oneMore("lvl101", 101);
	Form form2("FormFail");
	oneMore.signForm(form2);
}

void testSecondEx()
{
	constructorAndCopy();
	signSuccess();
	signFail();
	multipleSign();
	boundaryCases();
}

int main()
{
	// testFirstEx();
	testSecondEx();

	return 0;
}