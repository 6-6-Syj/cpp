/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:38:01 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 16:30:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[MAX_MATERIA];
	int _materiaCount;

public:
	Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character(); // TODO: Check

	/* getters */
	std::string const &getName() const;

	/* actions */
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	/* utils */
	bool isSlotOccupied(int idx) const;
	void showInventory() const;
};