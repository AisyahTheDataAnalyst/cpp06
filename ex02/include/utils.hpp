/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:38:08 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 22:20:08 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstdlib>		// std::srand(), std::rand()
# include <ctime>		// std::time()
# include <iostream>	// std::cout
# include <exception>	// std::bad_cast &
# include "Base.hpp"

Base *generate(void);	
void identify(Base* p);
void identify(Base& p);

#endif