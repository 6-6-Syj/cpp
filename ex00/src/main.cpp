/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:46:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/16 16:26:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat ok("Ok", 150);
	
		std::cout << ok << std::endl;

		ok.decrementGrade();
		std::cout << ok << std::endl;
		
		ok.incrementGrade();
		std::cout << ok << std::endl;
		
		Bureaucrat not_ok("Not ok", 0);
		
		std::cout << not_ok << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}