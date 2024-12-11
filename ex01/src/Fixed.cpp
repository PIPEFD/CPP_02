/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:00 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 03:34:41 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;


Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "-------------------Default Constructor called---------------------------" << std::endl;

}


Fixed::Fixed(const int value)
{
    std::cout << "--------------------Int constructor called--------------------------" << std::endl;
    std::cout << "Value const int = " << value << std::endl;
    _fixedPointValue = value << _fractionalBits;
    std::cout << "_fixedPoint value  int = " << _fixedPointValue << std::endl;

}

Fixed::Fixed(const float value)
{
    std::cout << "--------------------Float constructor called--------------------------" << std::endl;
    std::cout << "Value  const float = " << value << std::endl;

    _fixedPointValue = roundf(value * (1 << _fractionalBits));
    std::cout << "_fixedPoint value float = " << _fixedPointValue << std::endl;
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


    _fixedPointValue = raw;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
}

float Fixed::toFloat(void) const
{
        std::cout << "--------------------toFloat called--------------------------" << std::endl;
        std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
        // if ()
        std::cout << "_fixedPoint Adrress = " << this.fixedPointValue << std::endl;
    

    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));    
}

int Fixed::toInt(void) const
{
    std::cout << "--------------------to Int called--------------------------" << std::endl;
    std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl;
        // if ()
        std::cout << "_fixedPoint Adrress = " << this << std::endl;
    return (_fixedPointValue >> _fractionalBits);    
}

void Fixed::printBits(void) const
{
    std::bitset<32> bits(_fixedPointValue);
    std::cout << "Binary represationn :" << bits << std::endl;   
}

// Sobrecarga del operador +
// Fixed Fixed::operator+(const Fixed &rhs) const {
//     return Fixed(this->toFloat() + rhs.toFloat());
// }

// // Sobrecarga del operador -
// Fixed Fixed::operator-(const Fixed &rhs) const {
//     return Fixed(this->toFloat() - rhs.toFloat());
// }

// // Sobrecarga del operador *
// Fixed Fixed::operator*(const Fixed &rhs) const {
//     return Fixed(this->toFloat() * rhs.toFloat());
// }

// // Sobrecarga del operador /
// Fixed Fixed::operator/(const Fixed &rhs) const {
//     if (rhs._fixedPointValue == 0) {
//         throw std::runtime_error("Division by zero");
//     }
//     return Fixed(this->toFloat() / rhs.toFloat());
// }

std::ostream &operator << (std::ostream &out, const Fixed &value)
{
    
    out << value.toFloat();
    // std::cout << "--------------------ostream &operato called--------------------------" << std::endl;

    // std::cout << &out << std::endl;
    return (out);
}