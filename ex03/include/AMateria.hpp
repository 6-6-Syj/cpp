/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:57:12 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 01:09:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	AMateria() {}
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria() {}

	std::string const &getType() const; // Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};