/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:04:47 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 01:04:54 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Cure
{
protected:
public:
	Cure() {}
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure() {}
};