/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:08:16 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/27 02:25:09 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sstream"
#include "limits"
#include "iostream"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::print(const std::vector<int> &chain) const
{
	for (size_t i = 0; i < chain.size(); i++)
		std::cout << chain[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::merge(std::vector<int> &arr, int left, int mid, int right)
{
	std::vector<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}

	while (i <= mid)
		temp.push_back(arr[i++]);
	while (j <= right)
		temp.push_back(arr[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		arr[left + k] = temp[k];
}

void PmergeMe::mergeSort(std::vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

std::vector<int> PmergeMe::generateInsertionOrder(int pendSize)
{
	std::vector<int> jacobsthalValues = jacobsthalSequence(pendSize);
	std::vector<int> insertionOrder;
	std::vector<bool> used(pendSize, false);

	int previousIndex = -1;

	for (size_t i = 0; i < jacobsthalValues.size(); i++)
	{
		int currentIndex = std::min(jacobsthalValues[i] - 1, pendSize - 1);

		for (int j = currentIndex; j > previousIndex; j--)
		{
			if (!used[j])
			{
				insertionOrder.push_back(j);
				used[j] = true;
			}
		}
		previousIndex = currentIndex;
		if (previousIndex >= pendSize - 1)
			break;
	}

	for (int i = 0; i < pendSize; i++)
	{
		if (!used[i])
			insertionOrder.push_back(i);
	}

	return insertionOrder;
}

void PmergeMe::binaryInsert(std::vector<int> &insertionOrder, std::vector<int> &main,
							std::vector<int> &pend, std::vector<int> &partners)
{
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		int pendIndex = insertionOrder[i];
		int valueToInsert = pend[pendIndex];
		int partnerVal = partners[pendIndex];

		std::vector<int>::iterator upperBound;
		if (partnerVal == std::numeric_limits<int>::min())
			upperBound = main.end();
			
		else
		{
			upperBound = std::lower_bound(main.begin(), main.end(), partnerVal);
			if (upperBound != main.end())
				++upperBound;
		}

		std::vector<int>::iterator it = std::lower_bound(main.begin(), upperBound, valueToInsert);
		std::cout << "Insert " << valueToInsert << " before main value: " << *it << "\n";
		main.insert(it, valueToInsert);
	}
}

void PmergeMe::appair(int n, char **av)
{
	std::vector<std::pair<int, int> > _pairs;

	for (int i = 1; i <= n; i += 2)
	{
		int a;
		std::istringstream(av[i]) >> a;

		if (i + 1 <= n)
		{
			int b;
			std::istringstream(av[i + 1]) >> b;

			if (a > b)
				std::swap(a, b);

			_pairs.push_back(std::make_pair(a, b));
		}
		else
			_pairs.push_back(std::make_pair(a, -1));
	}

	std::vector<int> main; // sorted highers
	std::vector<int> pend; // lowers
	std::vector<int> partners;

	for (size_t i = 0; i < _pairs.size(); i++)
	{
		if (_pairs[i].second != -1)
		{
			main.push_back(_pairs[i].second);
			pend.push_back(_pairs[i].first);
			partners.push_back(_pairs[i].second);
		}
		else
		{
			pend.push_back(_pairs[i].first);
			partners.push_back(std::numeric_limits<int>::min());
		}
	}

	std::cout << "Before binary insert with Jacobstalh :" << std::endl;
	std::cout << "  main : ";
	print(main);
	std::cout << "  pend : ";
	print(pend);
	std::cout << std::endl;

	std::vector<int> insertionOrder = generateInsertionOrder(pend.size());

	std::cout << "  insertion order:\n\t";
	for (size_t i = 0; i < insertionOrder.size(); i++)
		std::cout << insertionOrder[i] << " ";
	std::cout << "\n\n";

	for (size_t i = 0; i < insertionOrder.size(); i++)
		std::cout << "[" << insertionOrder[i] << "]: " << pend[insertionOrder[i]] << "\n";
	std::cout << "\n"
			  << std::endl;

	// binary insert with Jacobstalh
	binaryInsert(insertionOrder, main, pend, partners);

	std::cout << "\nFinal result: ";
	print(main);
}

// ########################################

std::vector<int> jacobsthalSequence(int n)
{
	std::vector<int> seq;
	int j0 = 1, j1 = 1;
	while (j1 <= n)
	{
		seq.push_back(j1);
		int next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	seq.push_back(j1);
	return seq;
}

void parse(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream arg(av[i]);
		std::string err(av[i]);
		double d;

		if (!(arg >> d))
			throw std::out_of_range("'" + err + "' is not an int");

		if (d > static_cast<double>(std::numeric_limits<int>::max()))
			throw std::out_of_range("'" + err + "' is higher than INT_MAX");

		if (d < 0)
			throw std::out_of_range("'" + err + "' must be a positive value");
	}
}