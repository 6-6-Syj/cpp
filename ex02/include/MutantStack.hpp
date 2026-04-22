/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:33:08 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/22 09:31:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:

public:
	typedef typename Container::iterator          _it;
	typedef typename Container::const_iterator    _constIt;
	
	MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	_it begin();
};

#include "MutantStack.tpp"