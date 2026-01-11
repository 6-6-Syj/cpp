/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:02:51 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 12:52:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i, j;
    char c;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
	i = j = 0;
    while (++i < ac)
    {
		j = 0;
        while (av[i][j])
        {
            c = toupper(av[i][j++]);
        	std::cout << c;
        }
    }
    std::cout << std::endl;
    return 0;
}
