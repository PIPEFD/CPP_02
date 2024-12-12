/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:20:28 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 17:41:00 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Deafult constructor called " << std::endl;
}


Fixed::Fixed(const Fixed &other) :_fixedPointValue(other._fixedPointValue)
{
    std::cout << "here -->>" << other._fractionalBits << " "
            << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignement operator called :" << &rhs << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawbits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    
    std::cout << "setRawBits member function called" << std::endl;
    std::cout << " Raw value == " << raw << std::endl;
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << _fixedPointValue <<std::endl;
}