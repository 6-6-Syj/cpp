/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:13:08 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 15:15:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data
{
private:
	int _id;

public:
	Data(void);
	Data(const Data &other);
	Data &operator=(const Data &copy);
	~Data(void);
};