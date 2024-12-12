/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:27:46 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 12:19:05 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed area(const Point &a, const Point &b, const Point &c) {
    Fixed term1 = a.getX() * (b.getY() - c.getY());
    Fixed term2 = b.getX() * (c.getY() - a.getY());
    Fixed term3 = c.getX() * (a.getY() - b.getY());

    Fixed totalArea = term1 + term2 + term3;
    return (totalArea < Fixed(0) ? totalArea * Fixed(-1) / Fixed(2) : totalArea / Fixed(2));
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    return (totalArea == (area1 + area2 + area3));
}
