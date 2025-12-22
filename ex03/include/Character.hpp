/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:38:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:53:24 by jmagand          ###   ########.fr       */
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
	static const int MAX_HP;
	AMateria *inventory[MAX_MATERIA];
	int _hp;
	int _materiaCount;

public:
	Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	/* getters */
	virtual std::string const &getName() const;
	virtual int getHp() const;

	/* actions */
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	/* utils */
	void showInventory() const;
};