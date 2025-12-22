/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:03:28 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 01:04:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Ice
{
protected:
public:
	Ice() {}
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice() {}
};