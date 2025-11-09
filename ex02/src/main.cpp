/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:07:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/09 22:18:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Usage: ./program\n";
		return 1;
	}

	Base *base = generate();
	identify(base);	// uses the pointer param
	identify(base);	// uses the ref param

	return 0;
}