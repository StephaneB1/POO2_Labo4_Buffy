/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : FieldDisplayer.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include "FieldDisplayer.h"
#include <iostream>

void FieldDisplayer::display(const Field& field) const {

    for(size_t y = 0; y < field.getHeight(); ++y) {
        for(size_t x = 0; x < field.getWidth(); ++x) {
            if(y == 0 || y == field.getHeight() - 1) {
                if(x == 0) {
                    std::cout << "+";
                } else if (x == field.getWidth() - 1) {
                    std::cout << "+" << std::endl;
                } else {
                    std::cout << "-";
                }
            } else {
                if(x == 0) {
                    std::cout << "|";
                } else if (x == field.getWidth() - 1) {
                    std::cout << "|" << std::endl;
                } else {
                    // Display Humanoids here
                    std::cout << " ";
                }
            }
        }
    }

}
