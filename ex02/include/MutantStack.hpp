/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:33:08 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/22 12:40:58 by jmagand          ###   ########.fr       */
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
	typedef typename Container::iterator 				iterator;
	typedef typename Container::const_iterator 			const_iterator;
	typedef typename Container::reverse_iterator 		reverse_iterator;
	typedef typename Container::const_reverse_iterator 	const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"