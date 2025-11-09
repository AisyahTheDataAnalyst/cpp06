/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:15:51 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 17:17:34 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

// colours
# define CYAN			"\033[1;36m"
# define PURPLE			"\033[1;35m"
# define BLUE			"\033[1;34m"
# define YELLOW			"\033[1;33m"
# define GREEN			"\033[1;32m"
# define RED 			"\033[1;31m"
# define BLACK			"\033[1;30m"
# define WHITE			"\033[1;37m"
# define LIGHT_RED		"\033[0;91m"
# define LIGHT_GREEN	"\033[0;92m"
# define LIGHT_YELLOW	"\033[0;93m"
# define LIGHT_BLUE		"\033[0;94m"
# define LIGHT_MAGENTA	"\033[0;95m"
# define LIGHT_CYAN		"\033[0;96m"
# define GRAY			"\033[0;90m"
# define COLOR			"\033[0m"
# define RL_CYAN		"\001\033[1;36m\002"
# define RL_COLOR		"\001\033[0m\002"

# include <iostream>	// std::cout
# include <cstdlib>		// std::atof
# include <cmath>		// std::isnan, std::isinf
# include <limits> 		// std::numeric_limits
# include <string>		// std::string
# include <cctype>		// std::isdigit(), std::isalpha()
# include <iomanip>		// std::fixed, sid::setprecision()

class ScalarConverter
{
	private:
		//Not instantiable
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		// Helper
		static char		toChar(double d);
		static int		toInt(double d);
		static float	toFloat(double d);

		//Parsing
		static bool thereIsAlpha(std::string literals);
		static bool validSigns(std::string literals);

	public:
		static void		convert(std::string literals);
};

#endif