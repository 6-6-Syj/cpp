/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:39:17 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 13:13:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target) const;
};