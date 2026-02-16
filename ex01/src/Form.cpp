/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:27 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/16 17:18:24 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static const int _toSign = 100;
static const int _toExecute = 50;

Form::Form(): _name("Unknown"), _signed(false) {}

Form::~Form() {}

Form::Form(const Form &other)
{}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

void Form::beSigned(Bureaucrat test)
{
	
}