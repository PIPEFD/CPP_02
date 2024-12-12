/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:08:50 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 01:05:49 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"

int main() {
    Fixed a(2.5f), b(1.25f);

    // Pruebas de comparación
    // std::cout << "a > b: " << (a > b) << std::endl;
    // std::cout << "a < b: " << (a < b) << std::endl;

    // // Pruebas de aritmética
    // Fixed c = a + b;
    // std::cout << "a + b: " << c << std::endl;

    // c = a - b;
    // std::cout << "a - b: " << c << std::endl;

    // c = a * b;
    // std::cout << "a * b: " << c << std::endl;

    // c = a / b;
    // std::cout << "a / b: " << c << std::endl;

    // // Pruebas de incremento y decremento
    // std::cout << "++a: " << ++a << std::endl;
    // std::cout << "a++: " << a++ << std::endl;

    // Pruebas de min y max
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    return 0;
}
