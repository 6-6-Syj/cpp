/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:25:19 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 11:06:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Span
{
private:
	unsigned int _size;
	int *_arr;
	
public:
	Span();
	Span(unsigned int size);
	Span(const Span &copy);
	Span &operator=(const Span &other);
	~Span();
	
	Span &operator[](unsigned int x);
	void addNumber(int x);
};

ostream& operator<<(const Span sp)
{
	
}