/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 12:35:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

void testShrubberyBase()
{
    std::cout << "=== 1. ShrubberyCreationForm - base test ===" << std::endl;

    ShrubberyCreationForm form("TestForm");

    {
        Bureaucrat bob("bob", 150);

        std::cout << bob << std::endl
                  << "Form: " << form.getName() 
                  << " - sign: " << form.getSignInfo() 
                  << " | execute: " << form.getExecuteInfo() << std::endl;

        try
        {
            bob.executeForm(form);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try
        {
            bob.signForm(form);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    }

    Bureaucrat john("john", 145);  // signGrade = 145
    Bureaucrat jim("jim", 137);   // execGrade = 137

    std::cout << std::endl << "=== 2. Signing tests ===" << std::endl;

    try
    {
        john.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        jim.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== 3. Execution tests (ShrubberyCreationForm) ===" << std::endl;

    Bureaucrat john_low("john_low", 145);
    Bureaucrat john_high("john_high", 136);
    Bureaucrat jim_high("jim_high", 137);

    try
    {
        john_low.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        john_high.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        jim_high.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testRobotomy()
{
    std::cout << "=== 5. RobotomyRequestForm tests ===" << std::endl;

    RobotomyRequestForm robotomyForm("TargetRobot");

    Bureaucrat robotBureaucrat("RoboBureaucrat", 45);
    Bureaucrat tooLow("TooLow", 50);

	robotBureaucrat.signForm(robotomyForm);
    for (int i = 0; i < 5; ++i)
    {
        try
        {
            robotBureaucrat.executeForm(robotomyForm);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

	try
	{
		tooLow.executeForm(robotomyForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

    std::cout << std::endl;
}

void testPresidentialPardon()
{
    std::cout << "=== 6. PresidentialPardonForm tests ===" << std::endl;

    PresidentialPardonForm pardonForm("TargetPardon");

    Bureaucrat pardonBureaucrat("PardonBureaucrat", 5);
    Bureaucrat pardonLow("PardonLow", 10);

	pardonBureaucrat.signForm(pardonForm);
    try
    {
        pardonBureaucrat.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        pardonLow.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testPolymorphism()
{
    std::cout << "=== 7. Polymorphism via AForm* ===" << std::endl;

    Bureaucrat highLevel("HighLevel", 1);
    Bureaucrat tooLowPoly("TooLowPoly", 50);

    AForm *forms[] = {
        new ShrubberyCreationForm("PolyTree"),
        new RobotomyRequestForm("PolyRobot"),
        new PresidentialPardonForm("PolyPardon")
    };
    const int nbForms = 3;

    for (int i = 0; i < nbForms; ++i)
    {
		std::cout << std::endl;
		highLevel.signForm(*forms[i]);
        std::cout << "\nForm " << i << " (" << forms[i]->getName() << "):" << std::endl;

        highLevel.executeForm(*forms[i]);

        std::cout << "Now try with tooLowPoly:" << std::endl;
        try
        {
            tooLowPoly.executeForm(*forms[i]);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    for (int i = 0; i < nbForms; ++i)
        delete forms[i];
}

int main()
{
	srand(time(NULL));
	  
    testShrubberyBase();
    testRobotomy();
    testPresidentialPardon();
    testPolymorphism();

    return 0;
}