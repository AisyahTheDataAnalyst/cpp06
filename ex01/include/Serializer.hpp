/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:26:39 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 19:31:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>		// uintptr_t
# include <iostream>	// std::cout
# define BLUE			"\033[1;34m"
# define LIGHT_YELLOW	"\033[0;93m"
# define PURPLE			"\033[1;35m"
# define GREEN			"\033[1;32m"
# define RED 			"\033[1;31m"
# define RESET			"\033[0m"

class Serializer
{
	private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif