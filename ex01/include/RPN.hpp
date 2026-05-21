/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:08:54 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 11:05:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "stack"
#include "string"

class RPN {
private:
	std::stack<int> _values;

public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN();
	
	void process(std::string &arg);
};

void isValidExpression(std::string &arg);
