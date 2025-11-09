/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:46:48 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 21:12:57 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Usage: ./program\n";
		return 1;
	}

	Data ptr;

	ptr.str	= "Hello";
	ptr.num	= 3;
	ptr.c		= 'A';
	ptr.flag	= true;
	
	uintptr_t raw;
	raw = Serializer::serialize(&ptr);

	Data *newPtr;
	newPtr = Serializer::deserialize(raw);

	std::cout << LIGHT_YELLOW
	<< "====================================================================\n"
	<< "	Comparing results of deserialize data with original	\n"
	<< "====================================================================\n" << RESET;
	
	if (!raw || !newPtr)
		std::cerr << RED << "Deserialization failed" << RESET << std::endl;
	else
		std::cout
		<< PURPLE << "---Deserialization (pointer -> uintptr_t -> pointer)---\n"
		<< "Pointer Address: " << &newPtr << '\n'
		<< "std::string str: " << newPtr->str << '\n'
		<< "int num: " << newPtr->num << '\n'
		<< "char c: " << newPtr->c << '\n'
		<< "bool flag: " << newPtr->flag << '\n' << RESET
		<< BLUE << "---Original data---\n"
		<< "Pointer Address: " << &ptr << '\n'
		<< "std::string str: " << ptr.str << '\n'
		<< "int num: " << ptr.num << '\n'
		<< "char c: " << ptr.c << '\n'
		<< "bool flag: " << ptr.flag << '\n' << RESET
		<< GREEN << "Deserialization Successful!\n" << RESET << std::endl;
	return 0;
}