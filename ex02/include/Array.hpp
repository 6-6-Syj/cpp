/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:29:08 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/16 15:53:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
private:
	T *_content;
	unsigned int _size;

public:
	Array();
	Array(unsigned int size);
	Array(const Array &copy);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
};

#include "Array.tpp"