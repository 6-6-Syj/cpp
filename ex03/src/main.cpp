/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 16:18:24 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <string>

int main()
{
    {
        Intern someRandomIntern;

        {
            AForm *rrf = someRandomIntern.makeForm("robotomy request", "RobotomyForm");
            if (rrf)
            {
                std::cout << "target: " << rrf->getTarget() << std::endl;
                try
                {
                    Bureaucrat test("test", 145);
                    test.signForm(*rrf);
                }
                catch (std::exception const &e)
                {
                    std::cout << "(test) Exception: " << e.what() << std::endl;
                }

                try
                {
                    Bureaucrat high("high", 5);
                    high.executeForm(*rrf);
                }
                catch (std::exception const &e)
                {
                    std::cout << "(high) Exception: " << e.what() << std::endl;
                }

                try
                {
                    Bureaucrat high("high", 5);

                    high.signForm(*rrf);
                    high.executeForm(*rrf);
                }
                catch(const std::exception& e)
                {
                    std::cout << "(high) Exception: " << e.what() << std::endl;
                }
                
                delete rrf;
            }
            std::cout << std::endl;
        }

        {
            AForm *rrf = someRandomIntern.makeForm("presidential pardon", "PardonForm");
            if (rrf)
            {
                try
                {
                    Bureaucrat high("high", 5);
                    high.signForm(*rrf);
                    high.executeForm(*rrf);
                }
                catch (std::exception const &e)
                {
                    std::cout << "(high) Exception: " << e.what() << std::endl;
                }
                delete rrf;
            }
            std::cout << std::endl;
        }

        {
            AForm *rrf = someRandomIntern.makeForm("shrubbery creation", "ShrubberyForm");
            if (rrf)
            {
                try
                {
                    Bureaucrat high("high", 5);
                    high.signForm(*rrf);
                    high.executeForm(*rrf);
                }
                catch (std::exception const &e)
                {
                    std::cout << "(high) Exception: " << e.what() << std::endl;
                }
                delete rrf;
            }
            std::cout << std::endl;
        }

        {
            AForm *rrf = someRandomIntern.makeForm("unknown", "UnknownForm");
            if (rrf)
            {
                try
                {
                    Bureaucrat high("high", 5);
                    high.signForm(*rrf);
                    high.executeForm(*rrf);
                }
                catch (std::exception const &e)
                {
                    std::cout << "(high) Exception: " << e.what() << std::endl;
                }
                delete rrf;
            }
        }
    }

    return 0;
}