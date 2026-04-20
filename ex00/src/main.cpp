/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 09:03:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(-5);
    vec.push_back(3);
    vec.push_back(7);
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    easyfind(vec, -5);
    easyfind(lst, 40);

    return 0;
}