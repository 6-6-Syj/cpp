/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:25:19 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 14:10:54 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int _size;
	std::vector<int> _arr;
	
public:
	Span();
	Span(unsigned int size);
	Span(const Span &copy);
	Span &operator=(const Span &other);
	~Span();
	
	int &getValue(unsigned int &idx) const;
	unsigned int &getSize();
	void addNumber(int x);
	int shortestSpan();
	int longestSpan();
};

// std::ostream &operator<<(std::ostream &out, Span &sp);