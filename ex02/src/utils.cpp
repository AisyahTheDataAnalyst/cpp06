/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:04:10 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 22:23:44 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		return new A();
	else if (std::rand() % 3 == 0)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (A *a = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (B *b = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (C *c = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

// BELOW USE FORBIDDEN HEADER
// #include <typeinfo>   // std::bad_cast
// void Base::identify(Base& p)
// {
// 	try
// 	{
// 		(void)dynamic_cast<A &>(p);
// 		std::cout << "A" << std::endl;
// 	}
// 	catch(const std::bad_cast &) {}

// 	try
// 	{
// 		(void)dynamic_cast<B &>(p);
// 		std::cout << "B" << std::endl;
// 	}
// 	catch(const std::bad_cast &) {}

// 	try
// 	{
// 		(void)dynamic_cast<C &>(p);
// 		std::cout << "C" << std::endl;
// 	}
// 	catch(const std::bad_cast &) {}
// }


// dynamic_cast can throw an exception, 
// specifically a std::bad_cast exception, 
// but only when used with references. 
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception &e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception &e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception &e) {}
}