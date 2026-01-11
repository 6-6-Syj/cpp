/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:16:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:12:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie
{

private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	std::string getName() const;
	void setName(std::string name);
	void announce() const;
};

Zombie *zombieHorde(int N, std::string name);