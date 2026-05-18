/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:36:31 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 16:10:06 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void print(T &x) 
{
	std::cout << "value: " << x << std::endl;
}

template <typename T>
void iter(T* address, const size_t length, void (*fun)(T&))
{
	for (size_t i = 0; i < length; i++)
		fun(address[i]);
}

template <typename T>
void iter(T* address, const size_t length, void (*fun)(const T&))
{
	for (size_t i = 0; i < length; i++)
		fun(address[i]);
}
