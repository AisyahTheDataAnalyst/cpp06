/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:16:45 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 17:23:18 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// OCF - privated

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}


// methods

// starts from double that is the biggest of them all
// double > float > int > char
// double is broad enough to represent all numeric inputs
// 
void ScalarConverter::convert(std::string literals)
{
	double d;
	
	// ===handle special literals===
	if (literals == "nan" || literals == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literals == "+inf" || literals == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (literals == "-inf" || literals == "-inff")
		d = -std::numeric_limits<double>::infinity();
	else if (literals.empty() || !validSigns(literals) ||
		(literals.length() > 1 && thereIsAlpha(literals)))
	{
		std::cout
		<< "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible"
		<< std::endl;
		return ;
	}
	else if (literals.length() == 1 && std::isalpha(literals[0]))
	d = static_cast<double>(literals[0]);
	else
	d = std::atof(literals.c_str());
	// std::cout << "validSign: " << validSigns(literals) << '\n';


	// ===print char===
	char c = toChar(d);
	std::cout << "char: ";
	if (c == 0)
		std::cout << "impossible\n";
	else if (c == -1)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'\n";


	// ===print interger===
	int i = toInt(d);
	std::cout << "int: ";
	if ((i == 0 && (std::isnan(d) || std::isinf(d))) ||
		d > static_cast<double>(std::numeric_limits<int>::max()) ||
		d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "impossible\n";
	else
		std::cout << i << '\n';
	

	// ===print float===
	float f = toFloat(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f;
	// if (f - i == 0)
		// std::cout << ".0";
	std::cout << "f\n";
	

	// ===print double===
	std::cout << "double: " << d;
	// if (d - i == 0)
		// std::cout << ".0";


	std::cout << std::endl;
}

// ---PARSING---
bool ScalarConverter::thereIsAlpha(std::string literals)
{
	bool flag = false;
	for (size_t i = 0; i < literals.length(); ++i)
	{
		if (std::isalpha(literals[i]))
			flag = true;
	}
	return flag;
}

bool ScalarConverter::validSigns(std::string literals)
{
	int sign = 0;
	bool alnum = false;
	
	for (size_t i = 0; i < literals.length(); ++i)
	{
		if (std::isalnum(literals[i]))
			alnum = true;
		if (literals[i] == '-' || literals[i] == '+')
			++sign;
		if (((literals[i] == '-' || literals[i] == '+') && alnum == true) || sign > 1)
			return false;
	}
	return true;
}

// ---CONVERTER HELPER---
char ScalarConverter::toChar(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		return 0; // "impossible"
	char c = static_cast<char>(d);
	if (!std::isprint(c)) 
		return -1; // "Non diplayable"
	return c;
}

int ScalarConverter::toInt(double d)
{
	if (std::isnan(d) || std::isinf(d))
		return 0; // "impossible"
	int i = static_cast<int>(d);
	return i;
}

float ScalarConverter::toFloat(double d)
{
	float f = static_cast<float>(d);
	return f;
}
