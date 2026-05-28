/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:19:42 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/28 14:40:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sstream"
#include "limits"
#include "iostream"
#include <algorithm>

const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string RESET = "\033[0m";

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &other)
{
	if (this != &other)
	{
		_container = other._container;
	}
	return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
const T &PmergeMe<T>::getContainer() const
{
	return _container;
}

template <typename T>
void PmergeMe<T>::fordJohnsonSort(T &chain)
{
	std::cout << CYAN << "[fordJohnsonSort] Entrée: [" << RESET;
	for (size_t i = 0; i < chain.size(); i++)
		std::cout << GREEN << chain[i] << RESET << (i < chain.size() - 1 ? ", " : "");
	std::cout << CYAN << "] (size=" << chain.size() << ")\n"
			  << RESET;

	if (chain.size() <= 1)
		return;

	bool isOdd = (chain.size() % 2 != 0);
	int lastValue = 0;
	if (isOdd)
	{
		lastValue = chain.back();
		chain.pop_back();
		std::cout << YELLOW << "[fordJohnsonSort] Impair: dernier élément = " << lastValue << " stocké\n"
				  << RESET;
	}

	std::vector<std::pair<int, int> > pairsList;
	T main;

	std::cout << BLUE << "[fordJohnsonSort] Pairement des éléments:\n"
			  << RESET;
	for (size_t i = 0; i < chain.size(); i += 2)
	{
		int a = chain[i];
		int b = chain[i + 1];
		if (a < b)
			std::swap(a, b);

		std::cout << BLUE << "  Paire [" << i << "," << i + 1 << "]: "
				  << GREEN << chain[i] << ", " << chain[i + 1] << RESET
				  << BLUE << " → grand=" << YELLOW << a << RESET
				  << BLUE << ", petit=" << GREEN << b << "\n"
				  << RESET;

		pairsList.push_back(std::make_pair(a, b));
		main.push_back(a);
	}

	std::cout << CYAN << "[fordJohnsonSort] Récursion sur main...\n"
			  << RESET;
	fordJohnsonSort(main);

	std::cout << CYAN << "[fordJohnsonSort] main après tri récursif: [" << RESET;
	for (size_t i = 0; i < main.size(); i++)
		std::cout << YELLOW << main[i] << RESET << (i < main.size() - 1 ? ", " : "");
	std::cout << CYAN << "]\n"
			  << RESET;

	T pend;
	T synchronizedPairs;
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairsList.size(); ++j)
		{
			if (pairsList[j].first == main[i])
			{
				pend.push_back(pairsList[j].second);
				synchronizedPairs.push_back(pairsList[j].first);
				break;
			}
		}
	}

	std::cout << BLUE << "\npend = [";
	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::cout << pend[i];
		if (pend.size() - 1 != i)
			std::cout << " ";
	}
	std::cout << "]\n";

	T insertionOrder = generateInsertionOrder(pend.size());

	std::cout << MAGENTA << "[fordJohnsonSort] Ordre d'insertion: [" << RESET;
	for (size_t i = 0; i < insertionOrder.size(); i++)
		std::cout << GREEN << insertionOrder[i] << RESET << (i < insertionOrder.size() - 1 ? ", " : "");
	std::cout << MAGENTA << "]\n"
			  << RESET;

	std::cout << BLUE << "[fordJohnsonSort] Insertions binaires:\n"
			  << RESET;
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int idx = insertionOrder[i];
		int val = pend[idx];
		int partner = synchronizedPairs[idx];

		typename T::iterator bound = std::find(main.begin(), main.end(), partner);
		typename T::iterator it = std::lower_bound(main.begin(), bound, val);

		int pos = std::distance(main.begin(), it);
		std::cout << BLUE << "  Insertion #" << i << ": val=" << GREEN << val
				  << RESET << BLUE << ", partner=" << MAGENTA << partner
				  << RESET << BLUE << " → insère à position " << YELLOW << pos << "\n"
				  << RESET;

		main.insert(it, val);
	}

	if (isOdd)
	{
		std::cout << YELLOW << "[fordJohnsonSort] Insertion du dernier élément impair: " << lastValue << "\n"
				  << RESET;
		typename T::iterator it = std::lower_bound(main.begin(), main.end(), lastValue);
		main.insert(it, lastValue);
	}

	chain = main;
}

template <typename T>
T PmergeMe<T>::jacobsthalSequence(int n) const
{
	T seq;
	if (n <= 0)
		return seq;
	seq.push_back(1);
	int j0 = 1, j1 = 1;
	while (true)
	{
		int next = j1 + 2 * j0;
		if (next > n)
			break;
		seq.push_back(next);
		j0 = j1;
		j1 = next;
	}
	return seq;
}

template <typename T>
T PmergeMe<T>::generateInsertionOrder(int pendSize) const
{
	T order;

	if (pendSize <= 0)
		return order;

	if (pendSize == 1)
	{
		order.push_back(0);
		return order;
	}

	std::vector<bool> used(pendSize, false);
	T jacob = jacobsthalSequence(pendSize); // {1, 3, 5, 11, ...}

	std::cout << MAGENTA << "\n[GenInsertOrder] pendSize = " << pendSize << "\n"
			  << RESET;

	order.push_back(1);
	used[1] = true;
	int prev = 1;

	for (size_t i = 0; i < jacob.size(); ++i)
	{
		int cur = jacob[i];
		if (cur >= pendSize)
			break;
		if (cur <= prev)
			continue;

		std::cout << MAGENTA << "  Bloc Jacobsthal " << cur << " -> indices [";
		for (int j = cur; j > prev; --j)
		{
			if (!used[j])
			{
				order.push_back(j);
				used[j] = true;
				std::cout << " " << j;
			}
		}
		std::cout << " ]\n"
				  << RESET;
		prev = cur;
		if (prev >= pendSize - 1)
			break;
	}

	bool hasRest = false;
	for (int i = pendSize - 1; i > 1; --i)
	{
		if (!used[i])
		{
			if (!hasRest)
			{
				std::cout << MAGENTA << "  Reste (décroissant) : [";
				hasRest = true;
			}
			order.push_back(i);
			used[i] = true;
			std::cout << " " << i;
		}
	}
	if (hasRest)
		std::cout << " ]\n"
				  << RESET;

	if (!used[0])
	{
		std::cout << MAGENTA << "  Dernier : index 0 (premier petit)\n"
				  << RESET;
		order.push_back(0);
	}

	std::cout << MAGENTA << "[GenInsertOrder] Ordre final : [";
	for (size_t i = 0; i < order.size(); ++i)
		std::cout << " " << order[i];
	std::cout << " ]\n"
			  << RESET;

	return order;
}

template <typename T>
void PmergeMe<T>::process(int n, char **av)
{
	T input;
	for (int i = 1; i <= n; ++i)
	{
		int value;
		std::istringstream(av[i]) >> value;
		input.push_back(value);
	}

	std::cout << BLUE << "[process] Entrée: [" << RESET;
	for (size_t i = 0; i < input.size(); i++)
		std::cout << GREEN << input[i] << RESET << (i < input.size() - 1 ? ", " : "");
	std::cout << BLUE << "]\n"
			  << RESET;

	fordJohnsonSort(input);

	std::cout << BLUE << "[process] Résultat final (trié): [" << RESET;
	for (size_t i = 0; i < input.size(); i++)
		std::cout << GREEN << input[i] << RESET << (i < input.size() - 1 ? ", " : "");
	std::cout << BLUE << "]\n\n"
			  << RESET;

	_container = input;
}