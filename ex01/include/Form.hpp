/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/16 17:14:25 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	static const int _toSign;
	static const int _toExecute;

public:
	Form::Form();
	Form::~Form();
	Form& operator=(const Form &other);
	Form::Form(const Form &other);
	
	void beSigned(Bureaucrat test);
};