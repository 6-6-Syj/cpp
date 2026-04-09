/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:07:34 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:34:24 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdint>

struct Data
{
	int value;
	std::string name;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &other);
	~Serializer();

public:
	static Data *deserialize(uintptr_t raw);
	static uintptr_t serialize(Data *ptr);
};