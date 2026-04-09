/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:31:03 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 15:18:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    Data* ptrD1 = new Data();

    unsigned long long raw = Serializer::serialize(ptrD1);   // ptr → int
    Data* ptrD2 = Serializer::deserialize(raw);              // int → ptr

    std::cout << "ptrD1 addr: " << ptrD1 << std::endl;
    std::cout << "ptrD2 addr: " << ptrD2 << std::endl;
	if (ptrD1 == ptrD2)
   		std::cout << "Same" << std::endl;

    delete ptrD1;
    return 0;
}