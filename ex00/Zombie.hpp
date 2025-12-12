/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:02:22 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 15:11:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Zombie {
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	std::string getName() const;
	void 		announce() const;
private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);