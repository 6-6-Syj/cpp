/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:50:08 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:47:59 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Brain.hpp>

class AAnimal
{
protected:
	std::string _type;
	Brain *_brain;

public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	std::string getType() const;
	virtual void makeSound() const = 0;
};