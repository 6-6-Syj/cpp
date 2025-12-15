/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:54 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/15 19:38:35 by jmagand          ###   ########.fr       */
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
	std::cerr << "Usage: ./harl2.0 [COMMAND]" << std::endl;
	return 1;
}