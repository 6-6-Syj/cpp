/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 13:33:40 by jmagand          ###   ########.fr       */
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
        AForm *rrf;

        std::string name = "robotomy request";
        std::string target = "RobotomyForm";
        rrf = someRandomIntern.makeForm(name, target);

        if (rrf)
        {
            Bureaucrat test("test", 145);
            test.signForm(*rrf);
    
            Bureaucrat high("high", 5);
            high.executeForm(*rrf);
            std::cout << std::endl;

            rrf->beSigned(high);
            high.executeForm(*rrf);
            
            delete rrf;
            std::cout << std::endl;
            
            name = "presidential pardon";
            target = "PardonForm";
            rrf = someRandomIntern.makeForm(name, target);
            if (rrf)
            {
                rrf->beSigned(high);
                high.executeForm(*rrf);
        
                delete rrf;            
            }
            std::cout << std::endl;
            
            name = "shrubbery creation";
            target = "ShrubberyForm";
            rrf = someRandomIntern.makeForm(name, target);
            if (rrf)
            {
                rrf->beSigned(high);
                high.executeForm(*rrf);
        
                delete rrf;            
            }

            name = "unknown";
            target = "UnknownForm";
            rrf = someRandomIntern.makeForm(name, target);
            if (rrf)
            {
                rrf->beSigned(high);
                high.executeForm(*rrf);
        
                delete rrf;            
            }
        }
    }

    return 0;
}