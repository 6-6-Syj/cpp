/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:54 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/09 13:48:08 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl h;

	if (ac == 2)
	{
		h.complain(av[1]);
		return 0;
	}
	std::cout << "Usage: ./harl2.0 [COMMAND]" << std::endl;
	return 1;
}