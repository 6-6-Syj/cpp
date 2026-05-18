/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:36:28 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 13:50:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <sstream>

template <typename T>
typename T::iterator easyfind(T container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	
	if (it == container.end())
	{
		std::ostringstream oss;
        oss << "'" << value << "' not found.";
        throw std::runtime_error(oss.str());
	}
	return it;
}