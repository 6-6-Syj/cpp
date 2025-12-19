/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:12:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 16:49:34 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _energy;
	int _ad;

public:
	/* Orthodox canonical form */
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	
	/* Operator */
	ClapTrap &operator--();

	/* Getters */
	std::string getName();
	unsigned int getHp();
	unsigned int getEnergy();
	int getAd();
	void setAd(int ad);

	/* Actions */
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};