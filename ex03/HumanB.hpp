/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:47 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:26:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &type);
};