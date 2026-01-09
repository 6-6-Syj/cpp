/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:12:56 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 16:02:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_known[MAX_MATERIA];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();
	
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};