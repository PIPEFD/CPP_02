/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:00 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 21:43:12 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstring>
// #include <cstdint>


const int Fixed::_fractionalBits = 8;


Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "-------------------Default Constructor called---------------------------" << std::endl;

}


void Fixed:: printb(const unsigned char* buffer) {
    std::cout << "Bits: ";
    for (int i = sizeof(_fixedPointValue) - 1; i >= 0; --i) { // De mayor a menor byte
        for (int j = 7; j >= 0; --j) { // De mayor a menor bit
                std::cout << ((buffer[i] >> j) & 1); // Extraer y mostrar cada bit
            }
        }
        std::cout << std::endl;
}




Fixed::Fixed(const int value)
{

    std::cout << "--------------------Int constructor called--------------------------" << std::endl;
    
    _fixedPointValue = value << _fractionalBits;

    unsigned char buffer[sizeof(_fixedPointValue)];
    // std::memcpy(buffer, &_fixedPointValue, sizeof(_fixedPointValue)); // Copiar bytes a buffer
    
    std::cout << "Value const int = " << value << std::endl;
    std::cout << "_fixedPoint value  int = " << _fixedPointValue << std::endl;
    std::memcpy(buffer, &value, sizeof(_fixedPointValue));
    printb(buffer);
    std::cout << "----------------------------------------------" << std::endl;


}

Fixed::Fixed(const float value)
{
    std::cout << "--------------------Float constructor called--------------------------" << std::endl;
    std::cout << "Value  const float = " << value << std::endl;

    _fixedPointValue = roundf(value * (1 << _fractionalBits));
    unsigned char buffer[sizeof(_fixedPointValue)];
    std::memcpy(buffer, &_fixedPointValue, sizeof(_fixedPointValue));
    std::cout << "_fixedPoint value float = " << _fixedPointValue << std::endl;
    printb(buffer);
    std::cout << "----------------------------------------------" << std::endl;

}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Address of variable &other" << &other << std::endl;
    std::cout << "Value const -<>>>>> = " << other._fixedPointValue << std::endl;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
    

    *this = other;
}

Fixed  &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assigment operator called" << std::endl;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
    std::cout << " rhs._fixedPointValue = " << rhs._fixedPointValue << std::endl;
    if (this != &rhs)
        _fixedPointValue = rhs._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "-------------------Detructor called---------------------------" << std::endl;

}

int Fixed::getRawBits(void) const
{
        std::cout << "--------------------getRawBits called--------------------------" << std::endl;

    return (std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl, _fixedPointValue);    
}

void Fixed::setRawbits(int const raw)
{
    std::cout << "--------------------SetRawBits called--------------------------" << std::endl;

    std::cout << "Raw value = " << _fixedPointValue << std::endl;

    _fixedPointValue = raw;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
}

float Fixed::toFloat(void) const
{
        std::cout << "--------------------toFloat called--------------------------" << std::endl;
        std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));    
}

int Fixed::toInt(void) const
{
    std::cout << "--------------------to Int called--------------------------" << std::endl;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
    
    return (_fixedPointValue >> _fractionalBits);    
}

void Fixed::printBits(void) const
{
    std::bitset<32> bits(_fixedPointValue);
    std::cout << "Binary represationn :" << bits << std::endl;   
}


std::ostream &operator << (std::ostream &out, const Fixed &value)
{
    
    out << value.toFloat();
    // std::cout << "--------------------ostream &operato called--------------------------" << std::endl;
    // std::cout << &out << std::endl;
    return (out);
}