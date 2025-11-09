/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:26:30 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 18:55:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//OCF
Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{}

//methods
uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t res;
	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *res;
	res = reinterpret_cast<Data *>(raw);
	return res;
}