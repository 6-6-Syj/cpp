/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:58:35 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 15:12:55 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceStrings(std::string line, const std::string &s1, const std::string &s2)
{
	std::size_t occurence = line.find(s1);

	while (occurence != std::string::npos)
	{
		line.replace(line.find(s1), s1.length(), s2);
		occurence = line.find(s1);
	}
	return (line);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./Sed [filename] [s1] [s2]" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "Argument cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Failed to open \"" << av[1] << "\"" << std::endl;
		file.close();
		return 1;
	}

	std::string line;
	std::ofstream replaced((filename + ".replace").c_str());
	if (!replaced.is_open())
	{
		std::cerr << "Failed to open \"" << (filename + ".replace") << "\"" << std::endl;
		file.close();
		replaced.close();
		return 1;
	}

	while (std::getline(file, line))
		replaced << replaceStrings(line, s1, s2) << std::endl;

	file.close();
	replaced.close();
	return 0;
}