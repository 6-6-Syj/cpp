/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:31:03 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:56:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data d1 = {42, "test"};
	Data *ptrD1 = &d1;

	uintptr_t raw = Serializer::serialize(ptrD1);
	Data *ptrD2 = Serializer::deserialize(raw);

	if (ptrD1 == ptrD2)
		std::cout << "OK '" << ptrD1 << '\'' << std::endl;
	else
		std::cout << "KO" << std::endl
				  << "ptrD1: \'" << ptrD1 << '\'' << std::endl
				  << "ptrD2: \'" << ptrD2 << '\'' << std::endl;

	return 0;
}