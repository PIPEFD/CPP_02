/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:11:18 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 09:51:57 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x; // Coordenada X
    const Fixed _y; // Coordenada Y

public:
    Point();                             // Constructor por defecto
    Point(const float x, const float y); // Constructor con coordenadas
    Point(const Point &other);           // Constructor de copia
    // Point &operator=(const Point &rhs);  // Operador de asignación
    ~Point();                            // Destructor

    const Fixed &getX() const;           // Devuelve la coordenada X
    const Fixed &getY() const;           // Devuelve la coordenada Y
};

#endif
