/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:23 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 12:19:18 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointValue(0)
{
    // std::cout << "Deafult Constructir called" << std::endl;
    
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int Constructor called" << std::endl;
    // std::cout << "Value Int" << value << std::endl; 
    _fixedPointValue = value << _fractionalBits;
    // std::cout << "_fixedPoint value  int = " << _fixedPointValue << std::endl;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float Constructor called" << std::endl;
    // std::cout << "Value Float " << value << std::endl; 
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
    // std::cout << "_fixedPoint value float = " << _fixedPointValue << std::endl;

}
Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
    // std::cout << "Copy Assignement operator called" << std::endl;
    if (this !=  &rhs)
        _fixedPointValue = rhs._fixedPointValue;
    
    return (*this);       
}
Fixed::~Fixed()
{
    // std::cout << "Desctrutor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // return (std::cout << "_fixedPoint value = " << _fixedPointValue << std::endl, _fixedPointValue);    
    return (this->_fixedPointValue);
  
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "Raw value = " << raw << std::endl;
    this-> _fixedPointValue = raw;
    // std::cout << "_fixedPoint value set_rawbits " << _fixedPointValue << std::endl;
}

int Fixed::toInt(void) const
{
    // std::cout << "--------------------to Int called--------------------------" << std::endl;
    // std::cout << _fixedPointValue << " !! " << std::endl;
    return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
        // std::cout << "--------------------to Float called--------------------------" << std::endl;
        // std::cout << _fixedPointValue << " !! " << std::endl;
        // std::cout << this->toFloat() << "here!!" << std::endl;
        return(static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}


Fixed Fixed::operator+(const Fixed &rhs) const 
{
    // std::cout << " ----------------------------------" << std::endl;
    // std::cout << " here --> " << rhs._fixedPointValue << std::endl;    
    // std::cout << " this->tofloat()" << this->toFloat() << std::endl;    
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs._fixedPointValue == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return(_fixedPointValue > rhs._fixedPointValue);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return(_fixedPointValue < rhs._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return(_fixedPointValue >= rhs._fixedPointValue);
}


bool Fixed::operator<=(const Fixed &rhs) const
{
    return(_fixedPointValue <= rhs._fixedPointValue);
}


bool Fixed::operator==(const Fixed &rhs) const
{
    return(_fixedPointValue == rhs._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return(_fixedPointValue != rhs._fixedPointValue);
}


Fixed &Fixed::operator++() 
{ 
    _fixedPointValue++; 
    return *this; 
}
Fixed Fixed::operator++(int) 
{ 
    Fixed temp = *this; _fixedPointValue++; 
    return temp; 
}
Fixed &Fixed::operator--() 
{ 
    _fixedPointValue--; 
    return *this; 
}
Fixed Fixed::operator--(int) 
{     
    Fixed temp = *this; _fixedPointValue--; 
    return temp; 
}

// Métodos estáticos para min y max
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{ 
    return (a < b) ? a : b; 
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{ 
    return (a < b) ? a : b; 
}
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{ 
    return (a > b) ? a : b; 
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{ 
    return (a > b) ? a : b; 
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}