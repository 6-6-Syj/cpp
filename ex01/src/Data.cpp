/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:14:07 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 15:16:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _id(42) {}

Data::Data(const Data &other) : _id(other._id) {}

Data& Data::operator=(const Data &copy)
{
    if (this != &copy)
        _id = copy._id;
    return *this;
}

Data::~Data(void) {}