/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:21:40 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 16:09:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {};

static Base *generate()
{
	int choice = 1 + (rand() % 3);

	if (choice == 1)
		return new A();
	else if (choice == 2)
		return new B();
	else
		return new C();
}

static void identify(Base *p)
{
	std::cout << "by ptr" << std::endl;
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "C" << std::endl;
}

static void identify(Base &p)
{
	std::cout << "by ref" << std::endl;
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int main(void)
{
	srand(static_cast<unsigned>(time(NULL)));

	Base *base;

	base = generate();
	identify(base);
	identify(*base);
	
	if (base)
		delete base;
	return 0;
}