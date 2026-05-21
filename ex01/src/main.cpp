/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:08:49 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 15:05:19 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"inverted Polish mathematical expression\"" << std::endl
					<< "e.g.: ./RPN \"7 7 * 7 -\"" << std::endl;
		return 1;
	}
	try
	{
		std::string arg(av[1]);
		isValidExpression(arg);
		
		RPN rpn;
		rpn.process(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}