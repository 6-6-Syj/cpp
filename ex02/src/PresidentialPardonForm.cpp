/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:01:22 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 16:09:12 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int AForm::_toSign = 100;
const int AForm::_toExecute = 50;

/*

Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox

*/

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
