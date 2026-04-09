/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:08:01 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 15:04:19 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer() {}

unsigned long long Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<unsigned long long>(ptr);
}

Data *Serializer::deserialize(unsigned long long raw)
{
	return reinterpret_cast<Data*>(raw);
}
