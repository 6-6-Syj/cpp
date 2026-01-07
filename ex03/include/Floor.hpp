/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:04:37 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/07 16:06:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria;

class Floor
{
private:
	AMateria** _ptrs;
	int _capacity;
	int _size;
	void resize(int newCapacity);
public:
	Floor();
	Floor(const Floor& other);
	Floor &operator=(const Floor& other);
	~Floor();

	void pushBack(AMateria *materia);
};