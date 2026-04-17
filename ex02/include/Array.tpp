/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:51:29 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/17 12:26:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	this->_content = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_content[i] = T();
};

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_content = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_content[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &copy) : _size(copy._size)
{
	_content = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_content[i] = copy._content[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _content;
		_size = other._size;
		_content = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_content[i] = other._content[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_content)
		delete[] this->_content;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size || index < 0)
		throw(std::out_of_range("Out of bounds."));
	return (_content[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size || index < 0)
		throw(std::out_of_range("(const) Out of bounds."));
	return _content[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	// std::cout << _size << std::endl;
	return _size;
}
