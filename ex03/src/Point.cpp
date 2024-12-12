/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:17:58 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 12:08:24 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

// Operador de asignación
// Point &Point::operator=(const Point &rhs) {
//     return *this;
// }

Point::~Point() {}

const Fixed &Point::getX() const { return _x; }
const Fixed &Point::getY() const { return _y; }
