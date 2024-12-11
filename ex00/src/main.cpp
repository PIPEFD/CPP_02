/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:30:36 by pipe              #+#    #+#             */
/*   Updated: 2024/12/11 01:29:28 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
    
    Fixed DirectOb[3];
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Direct Objects Created in that Stack" << std::endl;
    for (int i = 0; i < 3; i++) {
        DirectOb[i].setRawBits(i * 10);
        std::cout << "Address of variable" << &DirectOb << std::endl;
        std::cout << "Direct Object Value " << i << ": " << DirectOb[i].getRawBits() << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    Fixed CopyOb = DirectOb[0];
    std::cout << "Copy Object Value: " << CopyOb.getRawBits() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    Fixed AssignOb;
    AssignOb = DirectOb[1];
    std::cout << "Assigned Object Value: " << AssignOb.getRawBits() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    
    Fixed* ArrayIndi = new Fixed[3];
    std::cout << "----------------------------------------------" << std::endl;

    std::cout << "Indirect Objects Created in that Heap" << std::endl;

    for (int j = 0; j < 3; j++) {
        ArrayIndi[j].setRawBits(j * 10);
        std::cout << "Address of variable" << &ArrayIndi << std::endl;
        std::cout << "Indirect Object Value " << j << ": " << ArrayIndi[j].getRawBits() << std::endl;
    }
        delete[] ArrayIndi;

    

    return 0;
}
