/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:45:39 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 18:09:01 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;

// std::cout << "----------------------A = ----//" << a << "//---------------------" << std::endl;
// std::cout << "Address of variable a  -->" << &a << std::endl;
Fixed b( 10 );
b.setRawbits(10);
std::cout << "----------------------B = ----//" << b.toFloat() << "//---------------------" << std::endl;
std::cout <<  b.toInt() + 42 << std::endl;
b.printBits();
return 0;
// std::cout << "Address of variable b  -->" << &b << std::endl;
// b.printBits();

Fixed const c( 5.75f );
Fixed result ( c + b);
c.printBits();

// std::cout << "----------------------C = ----//" << c << "//---------------------" << std::endl;

// std::cout << "Address of variable c  -->" << &c << std::endl;

// std::cout << "--------------------COPY CONSTRUCTOR CALLED--------------------------" << std::endl;
// Fixed const d( b );
// std::cout << "----------------------D = ----//" << d << "//---------------------" << std::endl;

// std::cout << "Address of variable d  -->" << &d << std::endl;

a = Fixed( 1234.4321f );
// std::cout << "----------------------A = ----//" << &a << "//---------------------" << std::endl;

// std::cout << "---------------- FIXED A = "<< a <<" ------------------------------"<< std::endl;

// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// // std::cout << "d is " << d << std::endl;
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// a.printBits();
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "---------------- B = "<< b <<" ------------------------------"<< std::endl;

// std::cout << "Address of variable B " << &b << std::endl;
// std::cout << "------------------B----------------------------" << std::endl;


// b.printBits();
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "Address of variable" << &b << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "----------------------------------------------" << std::endl;

// c.printBits();
// // std::cout << "----------------------------------------------" << std::endl;
// // std::cout << "Address of variable" << &c << std::endl;
// // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// // std::cout << "----------------------------------------------" << std::endl;

// // d.printBits();
// // std::cout << "----------------------------------------------" << std::endl;
// // std::cout << "Address of variable" << &d << std::endl;
// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
// std::cout << "----------------------------------------------" << std::endl;
// a.printBits();
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "Address of variable" << &a << std::endl;
// std::cout << "b is " << b.toFloat() << " as float" << std::endl;
// b.printBits();
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "Address of variable" << &b << std::endl;
// std::cout << "c is " << c.toFloat() << " as float" << std::endl;
// c.printBits();
// std::cout << "----------------------------------------------" << std::endl;
// std::cout << "Address of variable" << &c << std::endl;
// std::cout << "d is " << c.toFloat() << " as float" << std::endl;
// // d.printBits();
// std::cout << "----------------------------------------------" << std::endl;

return 0;
}
