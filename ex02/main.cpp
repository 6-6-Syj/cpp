/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:49:38 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:25:28 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string hi = "HI THIS IS BRAIN";
	std::string &ref = hi;
	std::string *ptr = &hi;

	std::cout << "string address: " << &hi << std::endl;
	std::cout << "ptr address: " << ptr << std::endl;
	std::cout << "ref address: " << &ref << std::endl;

	std::cout << "\nstring: " << hi << std::endl;
	std::cout << "pointed value by ptr: " << *ptr << std::endl;
	std::cout << "refered value by ref: " << ref << std::endl;
}