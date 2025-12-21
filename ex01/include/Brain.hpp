/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:20:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/21 23:34:39 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define MAX_IDEAS 100

class Brain
{
protected:
	std::string _ideas[MAX_IDEAS];

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(int i, std::string idea);
	std::string getIdea(int i) const;
};