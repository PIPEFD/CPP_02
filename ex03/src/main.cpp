/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:08:50 by dbonilla          #+#    #+#             */
/*   Updated: 2024/12/12 12:21:41 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"
#include <fstream>


void generateSVG(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &filename) {
    std::ofstream svgFile(filename.c_str());

    if (!svgFile) {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    svgFile << "<svg xmlns='http://www.w3.org/2000/svg' width='500' height='500' viewBox='-10 -10 20 20'>\n";
    svgFile << "<polygon points='" 
            << a.getX().toFloat() << "," << a.getY().toFloat() << " "
            << b.getX().toFloat() << "," << b.getY().toFloat() << " "
            << c.getX().toFloat() << "," << c.getY().toFloat()
            << "' style='fill:lightblue;stroke:blue;stroke-width:0.1'/>\n";
    svgFile << "<circle cx='" << p.getX().toFloat() << "' cy='" << p.getY().toFloat()
            << "' r='0.1' fill='red'/>\n";
    svgFile << "</svg>";

    svgFile.close();
    std::cout << "SVG generated: " << filename << std::endl;
}
int main() {
    Point a(2, 2);
    Point b(3, 2);
    Point c(2, 1);

    Point inside(2, 2);
    
    if (bsp(a, b, c, inside) == 1)
        generateSVG(a, b, c, inside, "triangle_inside.svg");
    else
        generateSVG(a, b, c, inside, "triangle_outside.svg");
    
    return 0;
}
