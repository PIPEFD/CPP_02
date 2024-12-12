/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:22:03 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 20:57:02 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <bitset>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const int);
        Fixed(const float);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &rhs);
        ~Fixed();


        int getRawBits(void) const;
        void setRawbits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        void printBits() const;
        void printb(const unsigned char* str);



};
    std::ostream &operator << (std::ostream &out, const Fixed &value);

#endif