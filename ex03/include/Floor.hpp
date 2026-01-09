/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:04:37 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 15:49:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MAX_MATERIA 4

class AMateria;

class Floor
{
private:
	static Floor *_floor;
	AMateria **_ptrs;
	int _capacity;
	int _size;

	Floor();
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);
	void resize(int newCapacity);

public:
	~Floor();

	static Floor* getFloor();
	void dropMateria(AMateria *materia);
	void displayFloor();
	void cleanFloor();
	static void destroyFloor();
};