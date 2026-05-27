/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:00:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/27 20:59:59 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>

template <typename T>
class PmergeMe
{
private:
	T _container;

	T 		generateInsertionOrder(int pendSize) const;
	T 		jacobsthalSequence(int n) const;
	void 	fordJohnsonSort(T &chain);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	const T &getContainer() const;
	void 	process(int n, char **av);
};

#include "../src/PmergeMe.tpp"