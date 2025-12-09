/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:02:51 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/09 15:44:17 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i, j;
    char c;

    j = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
	i = 0;
    while (++i < ac)
    {
		j = 0;
        while (av[i][j])
        {
            c = toupper(av[i][j++]);
        	std::cout << c;
        }
    }
    return (0);
}
