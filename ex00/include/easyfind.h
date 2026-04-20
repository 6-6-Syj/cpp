/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:36:28 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 09:04:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

template <typename T>
typename T::iterator easyfind(T container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	
	if (it == container.end())
		throw std::out_of_range("Value haven\'t been found");
	return it;
}