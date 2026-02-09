/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:58:35 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/09 14:08:12 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceStrings(std::string line, const std::string &s1, const std::string &s2)
{
	std::string result;
	std::size_t pos = 0;
	std::size_t last_pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		result.append(line.c_str() + last_pos, pos - last_pos);
		result += s2;
		pos += s1.length();
		last_pos = pos;
	}
	result.append(line.c_str() + last_pos, line.length() - last_pos);
	return result;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./Sed [filename] [s1] [s2]" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cout << "Argument cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Failed to open \"" << av[1] << "\"" << std::endl;
		file.close();
		return 1;
	}

	std::string line;
	std::ofstream replaced((filename + ".replace").c_str());
	if (!replaced.is_open())
	{
		std::cout << "Failed to open \"" << (filename + ".replace") << "\"" << std::endl;
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