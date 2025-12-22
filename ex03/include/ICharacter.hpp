/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:08:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:28:39 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

/*		
	Any copy(using copy constructor or copy operator) of a Character
	must be deep. During copy, the Materias of a Character
	must be deleted before the new ones are added to their inventory. 
	Of course, the Materias must be deleted when a Character is destroyed 			*/

class ICharacter
{
public:
	virtual ~ICharacter();
	virtual std::string const &getName() const = 0;
	virtual int getHp() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};