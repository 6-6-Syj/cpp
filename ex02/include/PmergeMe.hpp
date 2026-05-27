/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:00:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/27 02:15:40 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	void merge(std::vector<int> &arr, int left, int mid, int right);
	void mergeSort(std::vector<int> &arr, int left, int right);
	void print(const std::vector<int> &chain) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void appair(int n, char **av);
	std::vector<int> generateInsertionOrder(int pendSize);
	void binaryInsert(std::vector<int> &insertionOrder, std::vector<int> &main, std::vector<int> &pend, std::vector<int> &partners);
};

std::vector<int> jacobsthalSequence(int n);
void parse(int ac, char **av);