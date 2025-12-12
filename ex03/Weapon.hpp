/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:51 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 17:38:06 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	std::string getType() const;
	void setType(std::string newType);

private:
	std::string _type;
};