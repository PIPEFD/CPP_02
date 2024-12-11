/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:17:11 by pipe              #+#    #+#             */
/*   Updated: 2024/12/09 21:20:16 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits;

    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &rhs);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif