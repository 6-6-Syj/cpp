/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:33:08 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/21 16:10:49 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class MutantStack
{
private:
	// type _attribut;

public:
	MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();
};