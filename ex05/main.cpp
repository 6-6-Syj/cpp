/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:54 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/13 17:06:05 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl	h;
	
	h.complain("INFO");
	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("");
	return 0;
}